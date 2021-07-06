from cs50 import get_int

height = 0

while (height <= 0 or height > 8):
    height = get_int("Height: ")

# outer loop for each line
for i in range(1, height + 1):

    # prints the spaces at the start of each line
    for j in range(height - i):
        print(end=" ")

    # prints # at the end of line
    for k in range(i):
        print('#', end="")

    # prints a new line
    print()