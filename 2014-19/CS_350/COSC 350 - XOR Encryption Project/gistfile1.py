from operator import xor as _xor_

a = (raw_input("Enter in the plain text: "))
b = (raw_input("Enter in the secret key: "))

def xor(a, b):
    try:
        if len(a) is not 1 and len(b) is not 1:
            result = []
            for i in range(0,len(a)):
                result.append(xor(a[i], b[i]))
            return result
        else:
            if isinstance(a, str):
                a = ord(a)
            if isinstance(b, str):
                b = ord(b)
            return _xor_(a, b)
    except TypeError:
            return _xor_(a, b)    
    