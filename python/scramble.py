#!/usr/bin/env python
# coding: utf-8

# In[ ]:


"""
Write a function called "scramble" that accepts a string
as an argument and returns a new string. The new string
should start with the last half of the original string
and end with the first half.
#
If the length of the string is odd, split the string
at the floor of the length // 2 (in other words, the second
half is the longer half).

#For example:
  scramble("ab") -> "ba"
  screamble("abc") -> "bca"
  scramble("railroad")) -> "roadrail"
  scramble("fireworks")) -> "worksfire"
"""

#Write your function here!
def scramble(s):
    return s[len(s)//2:] + s[:len(s)//2]


#The following lines test your function. 
#feel free to change them to test things out.
string1 = "ab"
string2 = "abc"
string3 = "railroad"
string4 = "fireworks"
print(string1 + " -> " + scramble(string1))
print(string2 + " -> " + scramble(string2))
print(string3 + " -> " + scramble(string3))
print(string4 + " -> " + scramble(string4))

