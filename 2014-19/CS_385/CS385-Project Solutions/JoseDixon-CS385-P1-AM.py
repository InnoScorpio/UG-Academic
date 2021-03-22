# -*- coding: utf-8 -*-
"""
Created on Fri Feb 16 01:08:40 2018

@author: Jose Dixon
"""

# Executed in Python 2.7 using Anaconda 5 and Spyder IDE
class DFA:

    current_state = None;

    def __init__(self, states, alphabet, transition_function, start_state, accept_states):

        self.states = states;

        self.alphabet = alphabet;

        self.transition_function = transition_function;

        self.start_state = start_state;

        self.accept_states = accept_states;

        self.current_state = start_state;

        return;

   

    def transition_to_state_with_input(self, input_value):

        if ((self.current_state, input_value) not in self.transition_function.keys()):

            self.current_state = None;

            return;

        self.current_state = self.transition_function[(self.current_state, input_value)];

        return;

   

    def in_accept_state(self):

        return self.current_state in accept_states;

   

    def go_to_initial_state(self):

        self.current_state = self.start_state;

        return;

   

    def run_with_input_list(self, input_list):

        self.go_to_initial_state();

        for inp in input_list:

            self.transition_to_state_with_input(inp);

            continue;

        return self.in_accept_state();

    pass;

states = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};

alphabet = {'c', 'e', 'i', 'l', 'p', 'o', 'w', 's', 'q', 'r', 't', 'f', 'm', 'd', 'x'};

tf = dict();
#0
tf[(0, 'c')] = 2;

tf[(0, 'e')] = 5;

tf[(0, 'i')] = 0;

tf[(0, 'l')] = 0;

tf[(0, 'p')] = 1;

tf[(0, 'o')] = 0;

tf[(0, 'w')] = 0;

tf[(0, 's')] = 3;

tf[(0, 'q')] = 0;

tf[(0, 'r')] = 0;

tf[(0, 't')] = 0;

tf[(0, 'f')] = 4;

tf[(0, 'm')] = 0;

tf[(0, 'd')] = 0;

tf[(0, 'x')] = 0;
#1
tf[(1, 'c')] = 0;

tf[(1, 'e')] = 0;

tf[(1, 'i')] = 0;

tf[(1, 'l')] = 0;

tf[(1, 'p')] = 0;

tf[(1, 'o')] = 10;

tf[(1, 'w')] = 0;

tf[(1, 's')] = 0;

tf[(1, 'q')] = 0;

tf[(1, 'r')] = 0;

tf[(1, 't')] = 2;

tf[(1, 'f')] = 0;

tf[(1, 'm')] = 0;

tf[(1, 'd')] = 0;

tf[(1, 'x')] = 0;
#2 
tf[(2, 'c')] = 0;

tf[(2, 'e')] = 6;

tf[(2, 'i')] = 0;

tf[(2, 'l')] = 8;

tf[(2, 'p')] = 0;

tf[(2, 'o')] = 3;

tf[(2, 'w')] = 0;

tf[(2, 's')] = 0;

tf[(2, 'q')] = 0;

tf[(2, 'r')] = 0;

tf[(2, 't')] = 2;

tf[(2, 'f')] = 0;

tf[(2, 'm')] = 0;

tf[(2, 'd')] = 0;

tf[(2, 'x')] = 0;
#3
tf[(3, 'c')] = 0;

tf[(3, 'e')] = 0;

tf[(3, 'i')] = 0;

tf[(3, 'l')] = 0;

tf[(3, 'p')] = 0;

tf[(3, 'o')] = 0;

tf[(3, 'w')] = 0;

tf[(3, 's')] = 0;

tf[(3, 'q')] = 13;

tf[(3, 'r')] = 0;

tf[(3, 't')] = 0;

tf[(3, 'f')] = 0;

tf[(3, 'm')] = 0;

tf[(3, 'd')] = 0;

tf[(3, 'x')] = 0;
#4
tf[(4, 'c')] = 0;

tf[(4, 'e')] = 0;

tf[(4, 'i')] = 0;

tf[(4, 'l')] = 0;

tf[(4, 'p')] = 0;

tf[(4, 'o')] = 0;

tf[(4, 'w')] = 0;

tf[(4, 's')] = 0;

tf[(4, 'q')] = 0;

tf[(4, 'r')] = 0;

tf[(4, 't')] = 0;

tf[(4, 'f')] = 0;

tf[(4, 'm')] = 11;

tf[(4, 'd')] = 0;

tf[(4, 'x')] = 0;
#5
tf[(5, 'c')] = 0;

tf[(5, 'e')] = 0;

tf[(5, 'i')] = 0;

tf[(5, 'l')] = 0;

tf[(5, 'p')] = 0;

tf[(5, 'o')] = 0;

tf[(5, 'w')] = 0;

tf[(5, 's')] = 0;

tf[(5, 'q')] = 0;

tf[(5, 'r')] = 0;

tf[(5, 't')] = 0;

tf[(5, 'f')] = 0;

tf[(5, 'm')] = 0;

tf[(5, 'd')] = 0;

tf[(5, 'x')] = 9;
#6
tf[(6, 'c')] = 0;

tf[(6, 'e')] = 0;

tf[(6, 'i')] = 7;

tf[(6, 'l')] = 0;

tf[(6, 'p')] = 0;

tf[(6, 'o')] = 0;

tf[(6, 'w')] = 0;

tf[(6, 's')] = 0;

tf[(6, 'q')] = 0;

tf[(6, 'r')] = 0;

tf[(6, 't')] = 0;

tf[(6, 'f')] = 0;

tf[(6, 'm')] = 0;

tf[(6, 'd')] = 0;

tf[(6, 'x')] = 0;
#7
tf[(7, 'c')] = 0;

tf[(7, 'e')] = 0;

tf[(7, 'i')] = 0;

tf[(7, 'l')] = 8;

tf[(7, 'p')] = 0;

tf[(7, 'o')] = 0;

tf[(7, 'w')] = 0;

tf[(7, 's')] = 0;

tf[(7, 'q')] = 0;

tf[(7, 'r')] = 0;

tf[(7, 't')] = 0;

tf[(7, 'f')] = 0;

tf[(7, 'm')] = 0;

tf[(7, 'd')] = 0;

tf[(7, 'x')] = 0;
#8
tf[(8, 'c')] = 0;

tf[(8, 'e')] = 0;

tf[(8, 'i')] = 0;

tf[(8, 'l')] = 0;

tf[(8, 'p')] = 0;

tf[(8, 'o')] = 0;

tf[(8, 'w')] = 0;

tf[(8, 's')] = 0;

tf[(8, 'q')] = 0;

tf[(8, 'r')] = 0;

tf[(8, 't')] = 0;

tf[(8, 'f')] = 0;

tf[(8, 'm')] = 0;

tf[(8, 'd')] = 0;

tf[(8, 'x')] = 0;
#9
tf[(9, 'c')] = 0;

tf[(9, 'e')] = 0;

tf[(9, 'i')] = 0;

tf[(9, 'l')] = 0;

tf[(9, 'p')] = 8;

tf[(9, 'o')] = 0;

tf[(9, 'w')] = 0;

tf[(9, 's')] = 0;

tf[(9, 'q')] = 0;

tf[(9, 'r')] = 0;

tf[(9, 't')] = 0;

tf[(9, 'f')] = 0;

tf[(9, 'm')] = 0;

tf[(9, 'd')] = 0;

tf[(9, 'x')] = 0;
#10
tf[(10, 'c')] = 0;

tf[(10, 'e')] = 0;

tf[(10, 'i')] = 0;

tf[(10, 'l')] = 0;

tf[(10, 'p')] = 0;

tf[(10, 'o')] = 0;

tf[(10, 'w')] = 8;

tf[(10, 's')] = 0;

tf[(10, 'q')] = 0;

tf[(10, 'r')] = 0;

tf[(10, 't')] = 0;

tf[(10, 'f')] = 0;

tf[(10, 'm')] = 0;

tf[(10, 'd')] = 0;

tf[(10, 'x')] = 0;
#11
tf[(11, 'c')] = 0;

tf[(11, 'e')] = 0;

tf[(11, 'i')] = 0;

tf[(11, 'l')] = 0;

tf[(11, 'p')] = 0;

tf[(11, 'o')] = 12;

tf[(11, 'w')] = 0;

tf[(11, 's')] = 0;

tf[(11, 'q')] = 0;

tf[(11, 'r')] = 0;

tf[(11, 't')] = 0;

tf[(11, 'f')] = 0;

tf[(11, 'm')] = 0;

tf[(11, 'd')] = 0;

tf[(11, 'x')] = 0;
#12
tf[(12, 'c')] = 0;

tf[(12, 'e')] = 0;

tf[(12, 'i')] = 0;

tf[(12, 'l')] = 0;

tf[(12, 'p')] = 0;

tf[(12, 'o')] = 0;

tf[(12, 'w')] = 0;

tf[(12, 's')] = 0;

tf[(12, 'q')] = 0;

tf[(12, 'r')] = 0;

tf[(12, 't')] = 0;

tf[(12, 'f')] = 0;

tf[(12, 'm')] = 0;

tf[(12, 'd')] = 8;

tf[(12, 'x')] = 0;
#13
tf[(13, 'c')] = 1;

tf[(13, 'e')] = 0;

tf[(13, 'i')] = 0;

tf[(13, 'l')] = 0;

tf[(13, 'p')] = 0;

tf[(13, 'o')] = 0;

tf[(13, 'w')] = 0;

tf[(13, 's')] = 0;

tf[(13, 'q')] = 0;

tf[(13, 'r')] = 14;

tf[(13, 't')] = 0;

tf[(13, 'f')] = 0;

tf[(13, 'm')] = 0;

tf[(13, 'd')] = 0;

tf[(13, 'x')] = 0;
#14
tf[(14, 'c')] = 0;

tf[(14, 'e')] = 0;

tf[(14, 'i')] = 0;

tf[(14, 'l')] = 0;

tf[(14, 'p')] = 0;

tf[(14, 'o')] = 0;

tf[(14, 'w')] = 0;

tf[(14, 's')] = 0;

tf[(14, 'q')] = 0;

tf[(14, 'r')] = 0;

tf[(14, 't')] = 8;

tf[(14, 'f')] = 0;

tf[(14, 'm')] = 0;

tf[(14, 'd')] = 0;

tf[(14, 'x')] = 0;

start_state = 0;

accept_states = {8};

d = DFA(states, alphabet, tf, start_state, accept_states);

test = raw_input("Input a key word ")


if d.run_with_input_list(test) is True: 
    print(test, 'is Accepted')
    
else:
    print(test, "is Rejected")
