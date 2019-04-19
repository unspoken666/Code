#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#等边三角形绘制
import turtle as t #引进turtle库，绘图，并起了一个别名
t.fd(100)
t.seth(120)
t.fd(100)
t.seth(240)
t.fd(100)

#叠加等边三角形绘制
import turtle as t
t.fd(50)
t.seth(120)
t.fd(50)
t.seth(0)
t.fd(50)
t.seth(-120)
t.fd(50)
t.seth(0)
t.fd(50)
t.seth(120)
t.fd(100)
t.seth(-120)
t.fd(100)

#无角正方形的绘制
import turtle as t
d = 50
for i in range(4):
    t.seth(90*i)
    t.penup()
    t.fd(d)
    t.pendown()
    t.fd(2*d)
    t.penup()
    t.fd(d)
    
#无角正方形的绘制
import turtle as t
d = 50
for i in range(4):
    t.penup()
    t.fd(d)
    t.pendown()
    t.fd(2*d)
    t.penup()
    t.fd(d)
    t.right(90)
    
#六角形绘制
import turtle as t
t.seth(90)
for i in range(6):
    t.right(60)
    t.fd(100)
t.seth(30)
for i in range(6):
    t.left(60)
    t.fd(100)
    t.right(120)
    t.fd(100)

#正方形螺旋线绘制
import turtle as t
for i in range(3,500,4):
    t.left(90)
    t.fd(i)
    t.left(90)
    t.fd(i)
    

