#!/usr/bin/env python
# coding: utf-8

# In[ ]:


"""
Write a program that asks the user for an input 'n'
(assume that the user enters a positive integer)
and prints only the boundaries of the triangle using
asterisks "*" of height 'n'.                                   #asterisks 星号
For example if the user enters 6 then the height of
the triangle should be 6 as shown below and there
should be no spaces between the asterisks on the top line:
******
*   *
*  *
* *
**
*
"""
#Write your code here!
n = eval(input("please input num:"))
for i in range(n):
    for j in range(n):
        if i == 0:
            print("*",end='')
            continue
        if j == 0 or i+j == n-1:
            print("*",end='')
        else:
            print(" ",end='')           
    print()  
    
#another method
n = int(input("Enter a positive integer: "))
if n > 1:
    print(n*"*")
    for x in range(n-1,1,-1):
        print("*" + (x-2)*" "+"*")
    print("*")
if n == 1:
    print("*")

