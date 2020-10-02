# python code to generate data
import random

for p in range(1, 5):
    fp = open("4-2-in" + str(p) + ".txt", "w")

    totalNum = random.randint(10, 60)
    numbers = []

    for i in range(0, totalNum):
        numbers.append(random.randint(0, 2 ** 20))
        fp.write(str(numbers[i]))

        if random.randint(0, 1) == 1:
            fp.write('+')
        else:
            fp.write('-')

    fp.write(str(random.randint(0, 2 ** 20)) + '=')
    fp.close()

    # string = ""
    # fp = open("4-2-in" + str(p) + ".txt", "r")
    # string = fp.read()
    # fp.close()

    # totalNum = random.randint(15, totalNum*3)
    # for i in range(0, totalNum):
    #     length = len(string)
    #     position = random.randint(0, length)

    #     string = string[:position] + ' ' + string[position:]
    #     fp = open("4-2-in" + str(p) + ".txt", "w")
    #     fp.write(string)
    #     fp.close()

    #     fp = open("4-2-in" + str(p) + ".txt", "r")
    #     string = fp.read()
    #     fp.close()
