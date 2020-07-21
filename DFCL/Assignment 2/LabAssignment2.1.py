import imaplib
from pprint import pprint

host = "imap.gmail.com"
username = "email@email.com"
password = "password"

# connect to host using ssl
imap = imaplib.IMAP4_SSL(host)      #create an IMAP4 class with SSL

# login to server
imap.login(username,password)
status, message = imap.select("Inbox",1)
typ, data= imap.list()
print("Response Code:",typ)
print("Response:")
pprint(data)

print("Status:", status)
print("message:", message)



imap.close()


