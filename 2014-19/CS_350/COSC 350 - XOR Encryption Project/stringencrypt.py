# -*- coding: utf-8 -*-
"""
Created on Fri Oct 20 17:35:59 2017

@author: Jose Dixon
"""
plaintext = (raw_input("Enter in the plain text"))
secretkey = (raw_input("Enter in the secret key"))
temp=0
offset = 1
while temp <len(plaintext):
    if offset>1:
        int_number = int(plaintext[temp:temp+offset])
    else:
        int_number = int(plaintext[temp])
    if temp==5:
        offset=2
    temp+=offset