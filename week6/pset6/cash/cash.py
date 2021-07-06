from cs50 import get_float

# ask user until non-negative value is provided
dollars = 0
while dollars <= 0:
    dollars = get_float("Change owed: ")

# convert the dollars into cents
cents = int(round(dollars * 100))

# counts the no of coins for change
coincount = 0
while (cents > 0):
    if cents >= 25:
        cents -= 25
        coincount += 1
    elif cents >= 10:
        cents -= 10
        coincount += 1
    elif cents >= 5:
        cents -= 5
        coincount += 1
    elif cents >= 1:
        cents -= 1
        coincount += 1

print(f"{coincount}")