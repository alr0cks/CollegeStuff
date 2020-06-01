import hashlib
from Crypto.PublicKey import RSA
from Crypto import Random
import ast

text = str(input())

result = hashlib.sha1(text.encode())
print(result.hexdigest())







