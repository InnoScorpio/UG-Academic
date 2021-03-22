

import pickle
from easyAI.AI.DictTT import DictTT

class TT:
   
    
    def __init__(self, own_dict = None):
        self.d = own_dict if own_dict != None else dict()
        
    def lookup(self, game):
       
        return self.d.get(game.ttentry(), None)
        
    def __call__(self,game):
       
        return self.d[game.ttentry()]['move']
        
    def store(self, **data):
          
        entry = data.pop("game").ttentry()
        self.d[entry] = data
        
    def tofile(self, filename):
      
        with open(filename, 'w+') as f:
            pickle.dump(self, f)
    
 
    def fromfile(self, filename):
      
        with open(filename, 'r') as f:
            pickle.load(self, filename)
