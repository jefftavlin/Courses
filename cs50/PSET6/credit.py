while True:
    number = input('Number: ')
    try:
        if int(number) > 0:
            break
    except ValueError:
        pass

mc = [str(i) for i in range(1,6)]
digits = [n for n in number][::-1]
result = str(sum([int(item) for item in ''.join([str((2 * int(n))) for n in digits[1::2]])]) + sum([int(n) for n in digits[0::2]]))[-1]

if (number[0:2] == '34' or number[0:2] == '37') and len(number) == 15 and result == '0':
    print('AMEX')

elif number[0] == '5' and number[1] in mc and len(number) == 16 and result == '0':
    print('MASTERCARD')

elif number[0] == '4' and (len(number) == 13 or len(number) == 16) and result == '0':
    print('VISA')

else:
    print('INVALID')
