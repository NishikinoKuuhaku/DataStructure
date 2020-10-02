# python code to generate data
import random

for p in range(9, 11):
    fp = open("4-1-in" + str(p) + ".txt", "w")

    totalNum = random.randint(100, 1000)
    numbers = []

    fp.write(str(totalNum) + "\n")

    for i in range(0, totalNum):
        numbers.append(random.randint(2**30, 2**31-1))
        fp.write(str(numbers[i]) + ' ')
