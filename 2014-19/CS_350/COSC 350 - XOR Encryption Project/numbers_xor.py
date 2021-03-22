# -*- coding: utf-8 -*-
"""
Created on Sun Oct 01 17:33:01 2017
"""
import numpy as np
print("\nEnter in the plaintext bits accordingly.")
pt1 = int(input("Input the first plaintext bit:"))
pt2 = int(input("Input the second plaintext bit:"))
pt3 = int(input("Input the third plaintext bit:"))
pt4 = int(input("Input the fourth plaintext bit:"))
pt5 = int(input("Input the fifth plaintext bit:"))
pt6 = int(input("Input the sixth plaintext bit:"))
pt7 = int(input("Input the seventh plaintext bit:"))
pt8 = int(input("Input the eighth plaintext bit:")) 

print("\nEnter in the encryption bits accordingly.")
kt1 = int(input("Input the first encryption key bit:"))
kt2 = int(input("Input the second encryption key bit:"))
kt3 = int(input("Input the third encryption key bit:"))
kt4 = int(input("Input the fourth encryption key bit:"))
kt5 = int(input("Input the fifth encryption key bit:"))
kt6 = int(input("Input the sixth encryption key bit:"))
kt7 = int(input("Input the seventh encryption key bit:"))
kt8 = int(input("Input the eighth encryption key bit:"))

ct1 = pt1 ^ kt1
ct2 = pt2 ^ kt2
ct3 = pt3 ^ kt3
ct4 = pt4 ^ kt4
ct5 = pt5 ^ kt5
ct6 = pt6 ^ kt6
ct7 = pt7 ^ kt7
ct8 = pt8 ^ kt8

print("\nXOR Encryption\n")
p_text = np.array([pt1,pt2,pt3,pt4,pt5,pt6,pt7,pt8])
k_text = np.array([kt1,kt2,kt3,kt4,kt5,kt6,kt7,kt8])
c_text = np.array([ct1,ct2,ct3,ct4,ct5,ct6,ct7,ct8])

print('The plain text:',''.join(map(str, p_text)))
print('The encryption key:',''.join(map(str, k_text)))
print('The ciphered text:',''.join(map(str, c_text)))

print("\nXOR Decryption\n")
k_text = np.array([kt1,kt2,kt3,kt4,kt5,kt6,kt7,kt8])
c_text = np.array([ct1,ct2,ct3,ct4,ct5,ct6,ct7,ct8])
#d_text = [c_text] ^ [k_text]
d_text = (np.bitwise_xor(c_text, k_text))

print('The ciphered text:', ''.join(map(str, c_text)))
print('The encryption key:', ''.join(map(str, k_text)))
print('The decrypted text:', ''.join(map(str, d_text)))

