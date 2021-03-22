# -*- coding: utf-8 -*-
"""
Created on Sat Sep 10 18:09:58 2016
# Assignment 1 - Question 3
@author: Jose Dixon
"""
even_total = 0
sqrt_total = 0
pow_total = 0
odd_total = 0
odd_digits = 0

for i in range (2, 101, 2):
    even_total += i
print "The sum of all of even numbers between 2 to 100 is ", even_total
    
for j in range (1, 101):
    sqrt_total += j * j
print "The sum of all numbers squared from 2^0 to 2^22 is ", sqrt_total

for k in range (0, 21):
    pow_total += pow(2, k)
print "All powers of 2^0 to 2^20 is ", pow_total

a = int(input("Input a as the lowest number: "))
b = int(input("Input b as the highest number: "))
for l in range (a, b + 1):
    if l % 2 == 0:
       odd_total += i
print "The sum of odd numbers ranged from a  to b ", odd_total

c = int(input("Input a number to calculate the sum of odd digits: "))  
while c > 0:
  digits = c % 10
  if digits % 2 != 0:
          odd_digits += digits
  c /= 10
print "The sum of odd digits from number is: ", odd_digits
    

 