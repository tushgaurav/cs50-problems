from cs50 import get_int

height = 0

# ask user for input until height is in between 0 and 9
while height <= 0 or height >= 9:
    height = get_int("Height: ")

# for the row
for i in range(1, height + 1):

    # print spaces
    for j in range(height - i):
        print(end=' ')

    # print # for the first part of the pattern
    for k in range(i):
        print('#', end='')

    # print 2 spaces bettwen the pattern
    for l in range(0, 2):
        print(end=' ')

    # print the last part of the pattern
    for m in range(i):
        print('#', end='')
    print()
