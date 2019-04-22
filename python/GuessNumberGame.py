#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# 猜数字游戏
import random

a = 10
b = 200
hiddenNumber = random.randint(a, b)
# random.randint(a,b) creates a integer [a,b]

name = input("Hello!What is your name?")

print("Well, {}, I am thinking of a number between {} and {}.".format(name,a,b))
userGuess = 0
GuessCount = 0

while not userGuess == hiddenNumber:
    userGuess = int(input("Take a guess: "))
    GuessCount += 1
    if userGuess > hiddenNumber:
        print("Your guess is too high.")
    elif userGuess < hiddenNumber:
        print("Your guess is too low.")
    elif userGuess == hiddenNumber:
        print("Good job, {}! You guessed my number in {} guesses!".format(name,GuessCount))
        str = input("Play again (y for yes, n for no)?")
        if str == "y":
            hiddenNumber = random.randint(a, b)
            userGuess = 0
            GuessCount = 0
        elif str == "n":
            print()

