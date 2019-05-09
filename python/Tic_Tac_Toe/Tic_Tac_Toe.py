#!/usr/bin/env python
# coding: utf-8

# In[1]:


import random
def drawBoard(board):
    """
    This function prints out the board that it was passed.
    Board is a list of 10 strings representing the board (ignore index 0)
    The board is numbered like the keyboard's number pad.
    """
    # please complete the codes
    for i in range(1,12):
        if i in [1,3,5,7,9,11]:
            for j in range(1,12):
                if j in [4,8]:
                    print("|",end="")
                else:
                    print(" ",end="")
        elif i in [2,6,10]:
            for j in range(1,12):
                if j in [4,8]:
                    print("|",end="")
                elif j in [2,6,10]:
                    if (i,j) == (2,2):
                        print(board[1],end="")
                    elif (i,j) == (2,6):
                        print(board[2],end="")
                    elif (i,j) == (2,10):
                        print(board[3],end="")
                    elif (i,j) == (6,2):
                        print(board[4],end="")
                    elif (i,j) == (6,6):
                        print(board[5],end="")
                    elif (i,j) == (6,10):
                        print(board[6],end="")
                    elif (i,j) == (10,2):
                        print(board[7],end="")
                    elif (i,j) == (10,6):
                        print(board[8],end="")
                    elif (i,j) == (10,10):
                        print(board[9],end="")   
                else:
                    print(" ",end="")
        else:
            for j in range(11):
                print("-",end="")  
        print()
    
    
def inputPlayerLetter():
    """
    Lets the player type which letter ('X' or 'O') they want to be.
    Returns a list with the player's letter as the first item, 
    and the computer's letter as the second.
    
    """
    # set the user's input to letter
    # if letter is neither 'X' nor 'O', ask user to input again
    # until letter is 'X' or 'O'
    flag = True
    while flag:
        letter = input("Do you want to be X or O?")
        if letter == "X":
            flag = False
            return ['X','O']
        elif letter == "O":
            flag = False
            return ['O','X']
    
    
    # if letter is 'X', return ['X','O']
    # else return ['O','X']

def whoGoesFirst():
    """ 
    randomly choose the player who goes first
    """
    # use the randint function in random module (look for the help manual)
    # then return a random integer from [0,1]
    # if the return integer is 0, return 'computer'
    # else return 'player'
    n = random.randint(0,1)
    if n == 0:
        return 'computer'
    else:
        return 'player'
       
def playAgain():
    """This function returns True if the player wants to play again, 
    otherwise it returns False"""
    print('Do you want to play again?(yes or no)')
    # write one line code to implement this function
    return True if input().lower().startswith('y') else False

def makeMove(board,letter,move):
    """This function adds the player's move to the board"""
    board[move] = letter
    
def isWinner(board,letter):
    """
    Given a board and a player's letter, 
    this function returns True if the player has won. 
    """
    return ((board[1]==letter and board[2]==letter and board[3]==letter)or 
            (board[4]==letter and board[5]==letter and board[6]==letter)or 
            (board[7]==letter and board[8]==letter and board[9]==letter)or 
            (board[1]==letter and board[4]==letter and board[7]==letter)or 
            (board[2]==letter and board[5]==letter and board[8]==letter)or 
            (board[3]==letter and board[6]==letter and board[9]==letter)or 
            (board[1]==letter and board[5]==letter and board[9]==letter)or 
            (board[3]==letter and board[5]==letter and board[7]==letter))

def isSpaceFree(board,move):
    """Return True if the passed move is free on the passed board"""
    # write one line of code to finish this function
    return True if board[move] == " " else False

def getPlayerMove(board):
    """Let the player type in their move."""
    # ask the player to input their move
    # until int(move) is a number between 1 to 9 and the move is free on board
    # then return move as a number
    print("What is your next move? (1-9)")
    move = eval(input())
    while not isSpaceFree(board,move) or move not in [1,2,3,4,5,6,7,8,9]: 
        move = eval(input())
    return move

def chooseRandomMoveFromList(board,movesList):
    """
    Returns a valid move from the passed list on the passed baord.
    Returns None if there is no valid move"""
    possibleMoves = []
    # for each move in movesList, 
    # if the move is free on board,
    # then add the move to possibleMoves
    for i in movesList:
        if board[i] == " ":
            possibleMoves.append(i)
    
    
    # if the length of possibleMoves is not 0
    # then randomly choose one and return it
    # else renturn None
    # you may need choice function in random module
    if len(possibleMoves) != 0:
        return random.choice(possibleMoves)
    else:
        return None
    
def getBoardCopy(board):
    copy_board = []
    for i in board:
        copy_board.append(i)
    return copy_board

def getComputerMove(board,computerLetter):
    """
    Given a board and the computer's letter, 
    determine where to move and return that move
    """
    if computerLetter == 'X':
        playerLetter = 'O'
    else:
        playerLetter = 'X'
    
    # Here is our algorithm for our Tic Tac Toe AI:
    # first, check if computer can win in the next move.
    # hint: for all the 9 positions, if the position is free, then make move;
    # if that move can make the computer win, then return the position.
    
    # FILL IN YOUR CODE HERE...
    for i in range(1,10):
        copy_board = getBoardCopy(board)
        if isSpaceFree(copy_board,i):
            makeMove(copy_board,computerLetter,i)
            if isWinner(copy_board,computerLetter):
                return i
    
            
    # check if the player could win on their next move, and block them.
    # otherwise, return the position that makes the player win
    # FILL IN YOUR CODE HERE...
    for i in range(1,10):
        copy_board = getBoardCopy(board)
        if isSpaceFree(copy_board,i):
            makeMove(copy_board,playerLetter,i)
            if isWinner(copy_board,playerLetter):
                return i
            
    # Try to take one of the corners, if they are free.
    move = chooseRandomMoveFromList(board,[1,3,7,9])
    if move != None:
        return move
    
    # Try to take the center, if it is free.
    if isSpaceFree(board,5):
        return 5
    
    # Move on one of the sides
    return chooseRandomMoveFromList(board,[2,4,6,8])

def isBoardFull(board):
    """
    Return True if every space on the board has been taken. 
    Otherwise return False.
    """
    for i in range(1,10):
        if board[i] == " ":
            return False
    return True
      
# the main body of the Tic Tac Toe 
print('Welcome to Tic Tac Toe!')
while True:
    # reset the board
    theBoard =  [' '] * 10 
    playerLetter, computerLetter = inputPlayerLetter()
    turn = whoGoesFirst()
    print('The ' + turn + ' will go first.')
    gameIsPlaying = True
    while gameIsPlaying:
        if turn == 'player': # player's turn
            # use your function to print out the board
            drawBoard(theBoard)
            # use your function to get player's move, and set it to variable move
            move = getPlayerMove(theBoard)
            # adds the player's move to the board
            makeMove(theBoard,playerLetter,move)
            # if the player has won
            if isWinner(theBoard,playerLetter):
                # print out the board
                drawBoard(theBoard)
                # print the prompt message "Hooray! You have won the game!"
                print("Hooray! You have won the game!")
                # set gameIsPlaying to False
                gameIsPlaying = False
            # else
            else:
                # if the board is full
                if isBoardFull(theBoard):
                    # print out the board
                    drawBoard(theBoard)
                    # print the prompt message "The game is a tie!"
                    print("The game is a tie!")
                    # end the loop
                    break
                # else
                else:
                    # set turn to computer
                    turn = 'computer'
        else:
            # computer's turn
            # get the computer move
            move = getComputerMove(theBoard,computerLetter)
            #  adds the computer's move to the board
            makeMove(theBoard,computerLetter,move)
            # if the computer has won
            if isWinner(theBoard,computerLetter):
                # print out the board
                drawBoard(theBoard)
                # print the prompt message "The computer has beaten you! You lose."
                print("The computer has beaten you! You lose.")
                # set gameIsPlaying to False
                gameIsPlaying = False
            # else
            else:
                # if the board is full
                if isBoardFull(theBoard):
                    # print out the board
                    drawBoard(theBoard)
                    # print the prompt message "The game is a tie!"
                    print("The game is a tie!")
                    # end the loop
                    break
                # else
                else:
                     # set turn to player.
                    turn = 'player'
                                  
    if not playAgain():
        break 


# In[ ]:




