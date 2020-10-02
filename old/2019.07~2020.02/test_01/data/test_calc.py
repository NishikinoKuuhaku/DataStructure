# python code to test code
import subprocess

exe_path = "C:/Users/APass/OneDrive/Tutor/Nio_Ku/test_01/ans/ans_2.exe"
score = 0

for i in range(1, 11):
    input_path = "C:/Users/APass/OneDrive/Tutor/Nio_ku/test_01/data/4-2/" + \
                 "4-2-in" + str(i) + ".txt"
    infp = open(input_path, "r")
    output_path = "C:/Users/APass/OneDrive/Tutor/Nio_ku/test_01/data/4-2/" + \
                  "4-2-out" + str(i) + ".txt"
    outfp = open(output_path, "r")

    thread = subprocess.Popen(exe_path,
                              stdin=infp,
                              stdout=subprocess.PIPE)
    result = str(thread.stdout.read(), encoding="utf-8")
    result = result.replace('\r', '').replace('\n', ' ')
    stdAns = str(outfp.read()).replace('\r', '').replace('\n', ' ')
    if stdAns == result:
        score += 2
        print("data-" + str(i) + ": ACCEPTED")
    else:
        print("data-" + str(i) + ": WRONG ANSWER")
    infp.close()
    outfp.close()

print("Total score: " + str(score) + "/20")
