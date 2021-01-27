""""
Assume s is a string of lower case characters.

Write a program that prints the number of times the string 'bob' occurs in s. For example, if s = 'azcbobobegghakl', then your program should print"""



Paste your code into this box 

count = []

for i in range(len(s)):
    try:
        if s[i] == 'b' and s[i+1] == 'o' and s[i+2] == 'b':
            count.append(1)
    except IndexError:
        pass
print(sum(count))
