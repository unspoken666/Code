#!/usr/bin/env python
# coding: utf-8

# In[ ]:


grade = float(input("Enter a grade(0-100):"))

if grade >= 95:
    print('成绩等级为：A plus')
    print('成绩绩点为：4.0')
elif grade >= 90:
    print('成绩等级为：A')
    print('成绩绩点为：3.9')
elif grade >= 84:
    print('成绩等级为：A minus')
    print('成绩绩点为：3.8')
elif grade >= 80:
    print('成绩等级为：B plus')
    print('成绩绩点为：3.6')
else:
    print('成绩在80分以下')
print('done')

