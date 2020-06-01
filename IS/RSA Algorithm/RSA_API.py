from Crypto.PublicKey import RSA
from Crypto import Random
import ast
from Crypto.Cipher import PKCS1_OAEP
from Crypto.Signature import PKCS1_v1_5

text = str(input("Enter the Message:"))
def GenerateKeys(text):
  random_generator = Random.new().read
  key = RSA.generate(1024, random_generator) 

  publickey = key.publickey()

  encrypted = PKCS1_OAEP.new(publickey).encrypt('text')
  print ("Encrypted Message:", encrypted)

  decrypted = key.decrypt(ast.literal_eval(str(encrypted)))
  print ("Decrypted Message:", decrypted)

GenerateKeys(text)


