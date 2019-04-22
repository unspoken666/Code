#!/usr/bin/env python
# coding: utf-8

# In[ ]:


# define a function named is_prime
# which takes an integer anum as parameter；
# if anum is a prime, then return True; else return False;
# your code is here
#写出思路  每10个输出一行
# [2,n-1]
# [2,n//2]
# [2,int(sqrt(n))]
# 欧几里得筛选法 2的倍数去掉，3的倍数去掉，4的倍数去掉
# 小的素数表生成大素数表 2,3,5,7,11，
# 6x-1 6x+1 6x+5   m % 6 = 1  m % 6 = 5  (m > 5)
import math
def Is_prime(x):
    for i in range(2,x):
        j = 2
        if i in [2,3,5]:
            print(i,end=" ")
        elif i%6 == 1 or i%6 == 5:
            for j in range(2,int(math.sqrt(i))+1):
                if i%j == 0:
                    break
            else:
                print(i,end=" ")
                
# 调用函数，输出100以内的所有素数
Is_prime(100)
    

