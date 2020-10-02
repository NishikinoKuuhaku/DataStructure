# python code to test code
import subprocess

exe_path = "C:/Users/APassbyDreg/OneDrive/Tutor/Nio_Ku/test_01_retest/#ans/ans_1.exe"
score = 0

for i in range(1, 11):
    input_path = "C:/Users/APassbyDreg/OneDrive/Tutor/Nio_ku/test_01_retest/#data/4-1/" + \
                 "4-1-in" + str(i) + ".txt"
    infp = open(input_path, "r")
    output_path = "C:/Users/APassbyDreg/OneDrive/Tutor/Nio_ku/test_01_retest/#data/4-1/" + \
                  "4-1-out" + str(i) + ".txt"
    outfp = open(output_path, "r")

    thread = subprocess.Popen(exe_path,
                              stdin=infp,
                              stdout=subprocess.PIPE)
    result = str(thread.stdout.read(), encoding="utf-8").strip()
    stdAns = outfp.readline().strip()

    if stdAns == result:
        score += 3
        print("data-" + str(i) + ": ACCEPTED")
    else:
        print("data-" + str(i) + ": WRONG ANSWER")
    infp.close()
    outfp.close()

print("Total score: " + str(score) + "/30")
