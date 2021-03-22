

from easyAI import TwoPlayersGame, AI_Player, Negamax 
from easyAI.Player import Human_Player 

class GameController(TwoPlayersGame): 
    def __init__(self, players): 
        self.players = players 

        
        self.nplayer = 1 

       
        self.board = [0] * 16
    
    
    def possible_moves(self):
        return [a + 1 for a, b in enumerate(self.board) if b == 0]  
    
    
    def make_move(self, move):
        self.board[int(move) - 1] = self.nplayer 

    
    def loss_condition(self): 
        possible_combinations = [1, 5, 9, 13], [2, 6, 10, 14], [3, 7, 11, 15], [4, 8, 12, 16]
        [1, 2, 3, 4], [5, 6, 7, 8],[9, 10, 11, 12], [13, 14, 15, 16]
        return any([all([(self.board[i-1] == self.nopponent)
                for i in combination]) for combination in possible_combinations]) 
        
    
    def is_over(self):
        return (self.possible_moves() == []) or self.loss_condition()
        

    def show(self):
        print('\n'+'\n'.join([' '.join([['.', 'O', 'X'][self.board[4*j + i]]
                for i in range(4)]) for j in range(4)]))
                 
    
    def scoring(self):
        return -100 if self.loss_condition() else 0

if __name__ == "__main__":
   
    algorithm = Negamax(7)

  
    ''' GameController([Human_Player(), AI_Player(algorithm)]).play() '''
    GameController([Human_Player(), Human_Player()]). play()

