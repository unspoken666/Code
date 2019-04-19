#!/usr/bin/env python
# coding: utf-8

# In[ ]:


#MonConvert.py  
try:
    while 1:
        MonStr = input("请输入要转换的金额，例子:$2/￥4的形式，e退出:")
        if MonStr[0] == '$':
            R = eval(MonStr[1:]) * 6
            print("{}=>>${:.2f}".format(MonStr,R))
        elif MonStr[0] == '￥':
            D = eval(MonStr[1:])/6
            print("{}->>￥{:.2f}".format(MonStr,D))
        elif MonStr == 'e':
            break
        else:
            print("输入格式错误")
except:
    print("您输入有误")

