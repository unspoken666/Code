#!/usr/bin/env python
# coding: utf-8

# In[ ]:


'''设两个圆半径分别为R和r(R>=r),两圆心距为d,则
1)外离 ( d>R+r );

2)外切 ( d=R+r );

3)相交 ( R−r<d<R+r );

4)内切 ( d=R−r,R≠r );

5)内含 ( d<R−r );

6)重合 ( d=0,R=r );

两个圆的圆心位置和半径由用户输入。'''


import math

circle1_x,circle1_y = eval(input("Please input the center of the first circle (x1,y1): "))
radius1 = float(input("Please input the radius of the first circle: "))

circle2_x,circle2_y = eval(input("Please input the center of the second circle (x2,y2): "))
radius2 = float(input("Please input the radius of the second circle: "))

d = math.hypot(circle1_x - circle2_x,circle1_y-circle2_y) #计算两个数的平方和开根号  在这里即是两圆心间的距离
# your code here
if d > (radius1 + radius2):
    print("外离")
elif d == (radius1 + radius2):
    print("外切")
elif d > (radius1 - radius2) and d < (radius1 + radius2):
    print("相交")
elif d == (radius1 - radius2) and (radius1 != radius2):
    print("内切")
elif d < (radius1 - radius2):
    print("内含")
elif (d == 0) and (radius1 == radius2):
    print("重合")
    
    

