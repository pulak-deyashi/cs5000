from cs50 import get_float

while True:
    owed = get_float("Change owed: ")
    if owed > 0:
        break
coins = owed * 100
count = 0
if coins >= 25:
    count += (coins - (coins % 25)) / 25
    coins = coins % 25
if coins >= 10:
    count += (coins - (coins % 10)) / 10
    coins = coins % 10
if coins >= 5:
    count += (coins - (coins % 5)) / 5
    coins = coins % 5
count += coins
print(int(count))