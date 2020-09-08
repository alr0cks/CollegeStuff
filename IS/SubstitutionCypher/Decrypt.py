import random

alphabet = 'abcdefghijklmnopqrstuvwxyz.,! '
cipher = input("Enter the Text:")
key = input("Key:")
random.seed(key)

def makeKey(alphabet):
   alphabet = list(alphabet)
   random.shuffle(alphabet)
   return ''.join(alphabet)

def decrypt(cipher, key, alphabet):
    keyMap = dict(zip(key, alphabet))
    dec = ''.join(keyMap.get(c.lower(), c) for c in cipher)
    return dec
    
    
key = makeKey(alphabet)
print("Decrypted Message:",decrypt(cipher, key, alphabet))
