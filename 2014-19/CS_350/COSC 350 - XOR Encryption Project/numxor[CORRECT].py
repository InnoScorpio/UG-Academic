
print("Please enter your plaintext bits in binary.")
pt_bits1 = raw_input("PLAIN TEXT BITS ARE: ")
print('Please enter your key bits in binary. ')
kt_bits1 = raw_input("KEY BITS ARE: ")
print("THE ENCRYPTED/CIPHERED TEXT BELOW IS")
ct_text = int(pt_bits1, 2) ^ int(kt_bits1, 2)
print bin(ct_text)[2:].zfill(len(kt_bits1))

pretext = int(pt_bits1)
keytext = int(kt_bits1)
encrypt = pretext ^ keytext
decrypt = encrypt ^ keytext
print("THE DECRYPTED/ORGINAL TEXT IS", decrypt)
