#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#method one
#PythonDraw.py  
import turtle   
turtle.setup(650,350,200,200)
turtle.penup()
turtle.fd(-250)
turtle.pendown()
turtle.pensize(25)
turtle.pencolor("purple")
turtle.seth(-40)
for i in range(4):
    turtle.circle(40,80)
    turtle.circle(-40,80)
turtle.circle(40,80/2)
turtle.fd(40)
turtle.circle(16,180)
turtle.fd(40 * 2/3)
turtle.done()

#method two
#PythonDraw.py  
from turtle import *  
setup(650,350,200,200)
penup()
fd(-250)
pendown()
pensize(25)
pencolor("purple")
seth(-40)
for i in range(4):
    circle(40,80)
    circle(-40,80)
circle(40,80/2)
fd(40)
circle(16,180)
fd(40 * 2/3)
done()

#method three
#PythonDraw.py  
import turtle as t  
t.setup(650,350,200,200)
t.penup()
t.fd(-250)
t.pendown()
t.pensize(25)
t.pencolor("purple")
t.seth(-40)
for i in range(4):
    t.circle(40,80)
    t.circle(-40,80)
t.circle(40,80/2)
t.fd(40)
t.circle(16,180)
t.fd(40 * 2/3)
t.done()

#PythonDraw.py  绘制蟒蛇
import turtle as t  #引入了一个库 绘图库 海龟图
def Snake1(rader,angle,leng):
    for i in range(leng):
        t.circle(rader,angle)
        t.circle(-rader,angle)
        
def Snake2(rader,angle,neck):
    t.circle(rader,angle/2)
    t.fd(rader)
    t.circle(neck+1,180)
    t.fd(rader * 2/3)
    
def main():
    t.setup(1500,200,0,0)
    '''turtle.seth(180)
    turtle.up()
    fd(400)
    t.seth(0)
    t.pd()'''
    size = 30
    t.pensize(size)
    t.seth(-40)
    t.pencolor("red")
    Snake1(40,80,1)
    t.pencolor("orange")
    Snake1(40,80,1)
    t.pencolor("yellow")
    Snake1(40,80,1)
    t.pencolor("green")
    Snake1(40,80,1)
    t.pencolor("blue")
    Snake1(40,80,1)
    t.pencolor("purple")
    Snake2(40,80,size/2)
    
    
main()
    
