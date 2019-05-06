#!/usr/bin/env python
# coding: utf-8

# In[1]:


def isWordGuessed(secretWord, lettersGuessed):
    '''
    secretWord: string, the word the user is guessing
    lettersGuessed: list, what letters have been guessed so far
    returns: boolean, True if all the letters of secretWord are in lettersGuessed;
      False otherwise
    '''

    set1 = set(secretWord)
    set2 = set(lettersGuessed)
    if set1 <= set2:
        return True
    else:
        return False


def getGuessedWord(secretWord, lettersGuessed):
    '''
    secretWord: string, the word the user is guessing
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters and underscores that represents
      what letters in secretWord have been guessed so far.
    '''

    str1 = ""
    for i in range(len(secretWord)):
        str1 += "_ "
    ls = str1.split(" ")
    str1 = ""
    for it in lettersGuessed:
        if it in secretWord:
            ls[secretWord.index(it)] = it
            try:
                ls[secretWord.index(it,secretWord.index(it)+1)] = it
                ls[secretWord.index(it,secretWord.index(it)+1)] = it
                ls[secretWord.index(it,secretWord.index(it)+1)] = it
            except:
                pass

    for item in ls:
        str1 += item
        if item == "_":
            str1 += " "
    return str1

import string
def getAvailableLetters(lettersGuessed):
    '''
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters that represents what letters have not
      yet been guessed.
    '''

    str1 = string.ascii_lowercase
    ls = list(str1)
    for i in lettersGuessed:
        if i in ls:
            ls.remove(i)
    return "".join(ls)


import random
WORDLIST_FILENAME = "words.txt"
def loadWords():
    """
    Returns a list of valid words. Words are strings of lowercase letters.
    
    Depending on the size of the word list, this function may
    take a while to finish.
    """
    print("Loading word list from file...")
    inFile = open(WORDLIST_FILENAME, 'r')
    line = inFile.readline()
    wordlist = line.split()
    print("  ", len(wordlist), "words loaded.")
    return wordlist

def chooseWord(wordlist):
    """
    wordlist (list): list of words (strings)

    Returns a word from wordlist at random
    """
    return random.choice(wordlist)

def hangman(secretWord):
    '''
    secretWord: string, the secret word to guess.

    Starts up an interactive game of Hangman.

    * At the start of the game, let the user know how many 
      letters the secretWord contains.

    * Ask the user to supply one guess (i.e. letter) per round.

    * The user should receive feedback immediately after each guess 
      about whether their guess appears in the computers word.

    * After each round, you should also display to the user the 
      partially guessed word so far, as well as letters that the 
      user has not yet guessed.

    Follows the other limitations detailed in the problem write-up.
    '''
    # FILL IN YOUR CODE HERE...
    print("Welcome to the game,Hangman!")
    print("I am thinking of a word that is {} letters long.".format(len(secretWord)))
    mistakesMade = 0
    lettersGuessed = ""
    while not isWordGuessed(secretWord, lettersGuessed) and (8-mistakesMade):
        print("*"*10)
        print("You have {} guesses left.".format(8-mistakesMade))
        print("Available letters: ",getAvailableLetters(lettersGuessed))
        a = input("Please guess a letter: ")
        if a in lettersGuessed:
            print("Oops! You've already guessed that letter: ",getGuessedWord(secretWord, lettersGuessed))
        else:
            lettersGuessed += a
            if a in secretWord:
                print("Good guess:",getGuessedWord(secretWord, lettersGuessed))
            else:
                print("Oops! That letter is not in my word:",getGuessedWord(secretWord, lettersGuessed))
                mistakesMade += 1
    print("*"*10)
    if isWordGuessed(secretWord, lettersGuessed):
        print("Congratulations, you won!")
    elif mistakesMade == 8:
        print("Sorry, you ran out of guesses. The word was {}.".format(secretWord))
    return 

wordlist = loadWords()
secretWord = chooseWord(wordlist).lower()
hangman(secretWord)


# In[ ]:




