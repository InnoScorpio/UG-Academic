# -*- coding: utf-8 -*-
"""
Created on Sat Nov 17 22:46:24 2018

@author: Jose Dixon
"""
# This is a variant of the Tic Tac Toe recipe given in the easyAI library

from easyAI import TwoPlayersGame, AI_Player, Negamax # Import the code from files from the previous directory of codeAI to in work with this code.
from easyAI.Player import Human_Player # Import the code from files in the directory to in work with this code.

class GameController(TwoPlayersGame): # Calls a function to working in conjoin with another code to operate the two player game.
    def __init__(self, players): # This function defines the player. The player function is responsible for defining it as an entity.
        self.players = players #This defines players as entity of the game.

        # Define who starts the game
        self.nplayer = 1 #Defines who starts the game. The nplayer is the first to start the game

        # Define the board with a list of nine positions on the board.
        self.board = [0] * 16
    
    #This simply moves a or transition it through the list if is only occupied by one number.
    def possible_moves(self):
        return [a + 1 for a, b in enumerate(self.board) if b == 0]  
    
    # Make a move
    def make_move(self, move):
        self.board[int(move) - 1] = self.nplayer #This line basically take list of elements and checks for 1s and 0s.

    # These lines of code determines the possible combinations for the program that could determine a lost for the user.
    def loss_condition(self): 
        possible_combinations = [1, 5, 9, 13], [2, 6, 10, 14], [3, 7, 11, 15], [4, 8, 12, 16]
        [1, 2, 3, 4], [5, 6, 7, 8],[9, 10, 11, 12], [13, 14, 15, 16]
        return any([all([(self.board[i-1] == self.nopponent)
                for i in combination]) for combination in possible_combinations]) 
        
    # This line of code checks to see if the game is over based on the loss_condition method. 
    def is_over(self):
        return (self.possible_moves() == []) or self.loss_condition()
        
    # Show current possition on a 3x3 board. 
    def show(self):
        print('\n'+'\n'.join([' '.join([['.', 'O', 'X'][self.board[4*j + i]]
                for i in range(4)]) for j in range(4)]))
                 
    # Compute the score based on the loser. If the player loses points will be subtracted. 
    def scoring(self):
        return -100 if self.loss_condition() else 0

if __name__ == "__main__":
    # Define the algorithm where the AI will make a maximum of seven plays. 
    algorithm = Negamax(7)

    # Start the game with the first turn for the human then AI. 
    ''' GameController([Human_Player(), AI_Player(algorithm)]).play() '''
    GameController([Human_Player(), Human_Player()]). play()

