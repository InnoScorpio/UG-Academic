
class HashTT:
   
    def __init__(self):
        self.modulo = 1024 
    def before(self, key):
    
        return 0
    
    def after(self, key, hash):
      
        return hash
        
    def get_hash(self, key, depth = 0):
       
        ret_hash = self.before(key)
        if type(key) is int:
            return self.hash_int(key)
        if type(key) is str and len(key) <= 1:
            return self.hash_char(key)
        for v in list(key):
            ret_hash = self.join(ret_hash, self.get_hash(v, depth+1)) % self.modulo
        if depth == 0:
            ret_hash = self.after(key, ret_hash)
        return ret_hash
    
    def hash_int(self, number):
        
        return number
    
    def hash_char(self, string):
       
        return ord(string) 
    
    def join(self, one, two):
        
        return (one * two) % self.modulo