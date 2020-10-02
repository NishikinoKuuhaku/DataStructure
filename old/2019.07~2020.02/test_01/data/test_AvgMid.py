# python code to test code
import subprocess

exe_path = "C:/Users/APass/OneDrive/Tutor/Nio_Ku/test_01/AvgMid.exe"
score = 0

for i in range(1, 11):
    input_path = "C:/Users/APass/OneDrive/Tutor/Nio_ku/test_01/data/4-1/" + \
                 "4-1-in" + str(i) + ".txt"
    infp = open(input_path, "r")
    output_path = "C:/Users/APass/OneDrive/Tutor/Nio_ku/test_01/data/4-1/" + \
                  "4-1-out" + str(i) + ".txt"
    outfp = open(output_path, "r")

    thread = subprocess.Popen(exe_path,
                              stdin=infp,
                              stdout=subprocess.PIPE)
    ans_avg = str(thread.stdout.readline(), encoding="utf-8").strip()
    ans_mid = str(thread.stdout.readline(), encoding="utf-8").strip()
    std_avg = str(outfp.readline()).strip()
    std_mid = str(outfp.readline()).strip()

    if (ans_avg == std_avg) & (ans_mid == std_mid):
        score += 3
        print("data-" + str(i) + ": ACCEPTED")
    elif (ans_mid == std_mid):
        score += 2
        print("data-" + str(i) + ": PARTLY ACCEPTED (ERR_AVG)")
        print("\toutAvg: " + ans_avg)
        print("\tstdAvg: " + std_avg)
    elif (ans_avg == std_avg):
        score += 2
        print("data-" + str(i) + ": PARTLY ACCEPTED (ERR_MID)")
        print("\toutMid: " + ans_mid)
        print("\tstdMid: " + std_mid)
    else:
        print("data-" + str(i) + ": WRONG ANSWER")
        print("\toutAvg: " + ans_avg)
        print("\tstdAvg: " + std_avg)
        print("\toutMid: " + ans_mid)
        print("\tstdMid: " + std_mid)

    infp.close()
    outfp.close()

print("Total score: " + str(score) + "/30")
