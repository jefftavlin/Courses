while True:
    change = input('Change Owed: ')
    try:
        if float(change) > 0:
            change = float(change)
            break
    except ValueError:
        pass

coins, quarters, dimes, nickels, pennies = 0, 0, 0, 0, 0
cents = round(change * 100)

while cents >= 25:
    quarters += 1
    cents = cents - 25

while cents >= 10:
    dimes += 1
    cents = cents - 10

while cents >= 5:
    nickels += 1
    cents = cents - 5

while cents >= 1:
    pennies += 1
    cents = cents - 1

if cents == 1:
    pennies += 1

coins = quarters + dimes + nickels + pennies
print(coins)
