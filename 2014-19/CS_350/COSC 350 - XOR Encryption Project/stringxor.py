# -*- coding: utf-8 -*-
"""
Created on Thu Oct 12 00:03:14 2017

@author: Jose Dixon
"""
'''
import numpy as np
plain_text = (raw_input("Enter in the plain text :"))
secret_key = (raw_input("Enter in the secret key :"))

def str_xor(s1, s2):
 return "".join([chr(ord(c1) ^ ord(c2)) for (c1,c2) in zip(s1,s2)])
 

print result

i=0
count=0

while i < len(plain_text):
        count=count+1
        i=i+1
        encrypt_text = str_xor(secret_key, plain_text)
        e_array = np.array([encrypt_text])
        print('The encrypted text:',''.join(map(str, e_array)))
        
def encryptXOR(s, key)
 output = ""
     for i in count:
        for letter in key[::-1]:
            character = chr(ord(character) ^ ord(letter))
        output += character
    return output
        print('The encrypted text:',''.join(map(str, )))

decrypt_text = str_xor(encrypt_text, secret_key)
print("The decrypted text is:", decrypt_text)
'''
import sys
plaintext = (raw_input("Enter in the plaintext  : "))
secretkey = (raw_input("Enter in the secret key : "))
def encrypt1(plaintext, secretkey):
    return bytes(a ^ b for a,b in zip(plaintext, secretkey))
def decrypt1(plaintext, secretkey):
    secretkey = secretkey[:len(plaintext)]
    int_var = int.from_bytes(plaintext, sys.byteorder)
    int_key = int.from_bytes(secretkey, sys.byteorder)
    int_enc = int_var ^ int_key
    return int_enc.to_bytes(len(plaintext), sys.byteorder)

