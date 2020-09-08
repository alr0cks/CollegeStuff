 
import random

alphabet = 'abcdefghijklmnopqrstuvwxyz.,! '


plaintext = input("Enter the Text:")

key = input("Key:")

random.seed(key)

def makeKey(alphabet):
   alphabet = list(alphabet)
   random.shuffle(alphabet)
   return ''.join(alphabet)

def encrypt(plaintext, key, alphabet):
    keyMap = dict(zip(alphabet, key))
    enc = ''.join(keyMap.get(c.lower(), c) for c in plaintext)
    return enc


key = makeKey(alphabet)
cipher = encrypt(plaintext, key, alphabet)


print("Encrypted Message:" ,cipher)
