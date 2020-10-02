# python code to test code
import subprocess

exe_path = "C:/Users/APassbyDreg/OneDrive/Tutor/Nio_Ku/test_02/[4-2]WebCleaner.exe"
finalScore = 0

for i in range(1, 5):
    input_path = "C:/Users/APassbyDreg/OneDrive/Tutor/Nio_ku/test_02/#data/4-2/" + \
                 "4-2-in" + str(i) + ".txt"
    infp = open(input_path, "r")
    output_path = "C:/Users/APassbyDreg/OneDrive/Tutor/Nio_ku/test_02/#data/4-2/" + \
                  "4-2-out" + str(i) + ".txt"
    outfp = open(output_path, "r")

    thread = subprocess.Popen(exe_path,
                              stdin=infp,
                              stdout=subprocess.PIPE)
    ans = thread.stdout.readlines();
    std = outfp.readlines();

    score = 5
    if len(ans) == len(std):
        for j in range(0, len(std)):
            tmp1 = str(std[j]).strip()
            tmp2 = str(ans[j], encoding="utf-8").strip()
            if (tmp1 != tmp2):
                score -= 2
                print("\terror at line:" + str(j + 1))
    else:
        score = 0

    if score <= 0:
        score = 0
        print("data-" + str(i) + ": WRONG ANSWER")
    elif score == 5:
        print("data-" + str(i) + ": ACCEPTED")
    else:
        print("data-" + str(i) + ": PARTLY ACCEPTED")

    finalScore += score

    infp.close()
    outfp.close()

print("Total score: " + str(finalScore) + "/20")
