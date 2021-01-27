""""
Assume s is a string of lower case characters.

Write a program that counts up the number of vowels contained in the string s. 
Valid vowels are: 'a', 'e', 'i', 'o', and 'u'. For example, if s = 'azcbobobegghakl', your program should print:""""

# Paste your code into this box 
count = []
for item in s:
    if item in ['a','e','i','o','u']:
        count.append(item)
print(len(count))
