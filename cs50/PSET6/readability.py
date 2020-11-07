text = input('Text: ')

punc = ['.', '!', '?']

words = len([item for item in text if item == ' ']) + 1
sentences = len([item for item in text if item in punc])
letters = len([letter for letter in text if letter.isalpha()])

L = float(letters / words) * 100
S = float(sentences / words) * 100

index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print('Before Grade 1')

elif index >= 16:
    print('Grade 16+')

else:
    print(f'Grade {index}')
