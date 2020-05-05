from cs50 import get_int

n = get_int("Number: ")
i = 0
o = 0
e = 0
# copy the value to a new variable
c = n
# get the number of digits
while c > 0:
    c = int(c / 10)
    i += 1
# check whether the length is valid
if i in (13, 15, 16):
    r = int(n / 1000000000000)
    # using LUHN's Algorithm
    while n > 0:
        o += n % 10
        n = int(n / 10)
        e += (((n % 10) * 2) % 10) + int(((n % 10) * 2) / 10)
        n = int(n / 10)
    # if the last dight of the final sum of luhn's algo is 0
    if (o + e) % 10 == 0:
        if (i == 13 and r == 4) or (i == 16 and int(r / 1000) == 4):
            print("VISA")
        elif i == 15 and (int(r / 10) in (34, 37)):
            print("AMEX")
        elif i == 16 and (int(r / 100) in (51, 52, 53, 54, 55)):
            print("MASTERCARD")
        # if not satisfy for visa, amex , mastercard then invalid for this context
        else:
            print("INVALID")

    # if the last digit is NOT zero
    else:
        print("INVALID")
# if the length is not valid
else:
    print("INVALID")