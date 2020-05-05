from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n > 0 and n < 9:
        break

for i in range(n):
    # loop for printing spaces
    for j in range(n - i - 1):
        print(" ", end="")
    # loop for printing hashes
    for j in range(i + 1):
        print("#", end="")
    # printing new line
    print()

