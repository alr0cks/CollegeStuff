import math
import random
from decimal import Decimal

def checkPrime(x):
    if x > 1: 
      
        for i in range(2, x):
            if (x % i) == 0: 
                print(x, "is not a prime Number")
                y = 0
                break
        else: 
            print(x, "is a prime Number")
            y=1
    else: 
        print(x, "is not a prime Number")
        y=0
        
    return y


while(1):
    p = int(input("Enter the 1st Prime No."))
    q = int(input("Enter the 2nd Prime No."))
    a = checkPrime(p)
    b = checkPrime(q)
    fi = 0
    if(a==1 and b==1):
        n = p * q
        fi = (p-1)*(q-1)
        break
    else:
        print("Enter both Prime Numbers.\n")

def publicKey(fi):
    if(fi!=0):
        for e in range (2,fi):
            if(math.gcd(e,fi)==1):
            	return e
            
            
e = publicKey(fi)
print("Your Public Key:",e)

def privateKey():
    for i in range(1,10): 
        x = 1 + i*fi 
        if x%e == 0: 
            d = int(x/e) 
            break
    return d

d = privateKey()
print("Your Private Key:",d)

text = int(input("Enter the Text:"))
enc = pow(int(text),e)%n
print("Encrypted text:", enc)
dec = pow(int(enc),d)%n
print("Decrypted text:", dec)

