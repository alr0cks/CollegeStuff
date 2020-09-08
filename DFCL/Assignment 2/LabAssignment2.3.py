import imaplib
import email
from email.header import decode_header


from argparse import ArgumentParser

parser = ArgumentParser(description="Get email using imap")
parser.add_argument("-u", "--username", help="Gmail Address", type=str)
parser.add_argument("-p", "--password", help="password", type=str)
args = parser.parse_args()

host = "imap.gmail.com"
username = args.username
password = args.password

imap = imaplib.IMAP4_SSL(host)                  #create an IMAP4 class with SSL
imap.login(username, password)

status, total_email_id = imap.select("INBOX")          #select folder from where email is being fetched

total_email_id = int(messages[0])                     # total number of emails indexed by latest email recieved
current = total_email_id                                #get the latest email id
res, msg = imap.fetch(str(current), "(RFC822)")    #fetch email by ID
for response in msg:
    if isinstance(response, tuple):
        
        msg = email.message_from_bytes(response[1])         # parse email into a message object and decode it
        subject = decode_header(msg["Subject"])[0][0]
        if isinstance(subject, bytes):
            subject = subject.decode()
        from_ = msg.get("From")
        print("Subject:", subject)
        print("From:", from_)
        
        if msg.is_multipart():                          # if the email message is multipart
            for part in msg.walk():
                # extract content type of email
                content_type = part.get_content_type()
                content_disposition = str(part.get("Content-Disposition"))
                try:
                    body = part.get_payload(decode=True).decode()       # get the email body
                except:
                    pass
                if content_type == "text/plain" and "attachment" not in content_disposition:
                    print(body)
        else:
            content_type = msg.get_content_type()           #get content type of email
            body = msg.get_payload(decode=True).decode()     # get the email body
            if content_type == "text/plain":
                print(body)
imap.close()
imap.logout()
