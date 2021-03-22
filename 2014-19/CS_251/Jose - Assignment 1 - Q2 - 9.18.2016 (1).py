# -*- coding: utf-8 -*-
"""
Created on Sat Sep 10 16:14:54 2016
# Assignment 1 - Question 2
# This program will calculate the income tax for 
@author: Jose Dixon
"""
x = int(89000)
y = int(278000)

if x <= 50000:
    income_x = x * 0.01 
elif x <= 75000:
    income_x = x * 0.02
elif x <= 100000:
    income_x = x * 0.03
elif x <= 250000:
    income_x = x * 0.04
elif x <= 500000:
    income_x = x * 0.05
else: 
    income_x = x * 0.06
    
if y <= 50000:
    income_y = y * 0.01 
elif x <= 75000:
    income_y = y * 0.02
elif x <= 100000:
    income_y = y * 0.03
elif x <= 250000:
    income_x = y * 0.04
elif x <= 500000:
    income_y = y * 0.05
else: 
    income_y = y * 0.06
print "The income tax for $89,000 is $", income_x
print "The income tax for $278,000 is $", income_y