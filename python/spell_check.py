'''In this assignment you are asked to write a spell checker (corrector).
This assignment includes 3 parts.
In the first part you are asked to write a function to compare two strings and return 0, 1, or 2 according to the condition.
In the second part you are asked to write a function to check if a string can match another string by either inserting or deleting a character.
In the third part you are asked to write a function to correct spelling of a string (sentence) by using a list of correct words.
The third function uses the first two functions as helper functions.

Part1 :
Write a function named find_mismatch that accepts two strings as input arguments and returns:
0 if the two strings match exactly.
1 if the two strings have the same length and mismatch in only one character.
2 if the two strings do not have the same length or mismatch in two or more characters.
Capital letters are considered the same as lower case letters.

Part2 :
Write a function named single_insert_or_delete that accepts two strings as input arguments and returns:
0 if the two strings match exactly.
1 if the first string can become the same as the second string by inserting or deleting a single character. Notice that inserting and deleting a character is not the same as replacing a character.
2 otherwise
Capital letters are considered the same as lower case letters.

Part3 :
Write a function named spelling_corrector that accepts two arguments. The first argument is a sentence (string) and the second argument is a list of words (correct_spells).
Your function should check each word in the input string against all the words in the correct_spells list and return a string such that:
If a word in the original sentence matches exactly with a word in the correct_spells, then the word is not modified and it should be directly copied to the output string.
if a word in the sentence can match a word in the correct_spells list by replacing, inserting, or deleting a single character,then that word should be replaced by the correct word in the correct_spelled list.
If neither of the two previous conditions is true, then the word in the original string should not be modified and should be directly copied to the output string.
Notes:
Do not spell check one or two letter words (copy them directly to the output string).
In case of a tie use the first word from the correct_spelled list.
Ignore capitalization, i.e. consider capital letters to be the same as lower case letters.
All characters in the output string should all be in lower case letters.
Assume that the input string only includes alphabetic characters and spaces. (a-z and A-Z)
Remove extra spaces between the words.
Remove spaces at the start and end of the output string.'''

def find_mismatch(s1,s2):
    s1 = s1.lower()
    s2 = s2.lower()

    if s1 == s2:
        return 0
    flag = 0
    if len(s1) == len(s2):
        for i in range(len(s1)):
            if  s1[i] != s2[i]:
                 flag += 1
        if flag == 1:
            return 1
    else:
        return 2
                
def single_insert_or_delete(s1,s2):
    s1 = s1.lower()
    s2 = s2.lower()
    if s1 == s2:
        return 0
    
    if len(s1)-len(s2) < 0:
        s1,s2 = s2,s1
    if len(s1)-len(s2) == 1:
        for i in range(len(s1)):
            s = s1[0:i]+s1[i+1:] 
            if s == s2:
                return 1
    return 2

def spelling_corrector(s,ls):
    s = s.lower()
    s = s.strip(" ")
    ls1 = s.split(" ")
    for i in range(len(ls1)):
        for j in range(len(ls)):
             if find_mismatch(ls1[i],ls[j]) == 1 or single_insert_or_delete(ls1[i],ls[j]) == 1:
                    ls1[i] = ls[j]
    return " ".join(ls1).lower()

# use the examples to test function
print(spelling_corrector("Thes is the Firs cas",['that','first','case','car']))
print(spelling_corrector("programing is fan and eesy",['programming','this','fun','easy','book' ]))
print(spelling_corrector("Thes is vary essy",['this', 'is', 'very', 'very', 'easy']))
print(spelling_corrector("Wee lpve Pythen",['we', 'Live', 'In', 'Python']))
