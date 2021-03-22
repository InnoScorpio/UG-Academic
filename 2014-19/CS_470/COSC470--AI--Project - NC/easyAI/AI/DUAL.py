

from easyAI.AI.MTdriver import mtd

class DUAL:
   
    
    def __init__(self, depth, scoring=None, win_score=100000, tt=None):
        self.scoring = scoring        
        self.depth = depth
        self.tt = tt
        self.win_score= win_score
    
    def __call__(self,game):
      
        
        scoring = self.scoring if self.scoring else (
                       lambda g: g.scoring() ) 
        
        first = -self.win_score 
        next = (lambda lowerbound, upperbound, bestValue: bestValue + 1) 
        
        self.alpha = mtd(game, 
                         first, next,
                         self.depth, 
                         scoring,
                         self.tt)
        
        return game.ai_move
