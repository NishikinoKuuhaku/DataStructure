# python code to generate data output
import os
import subprocess

exe_path = "C:/Users/APassbyDreg/OneDrive/Tutor/Nio_Ku/test_02/"
exe_name = "[4-2]WebCleaner.exe"

for i in range(1, 5):
    input_path = "C:/Users/APassbyDreg/OneDrive/Tutor/Nio_ku/test_02/#data/4-2/"
    input_name = "4-2-in" + str(i) + ".txt"
    infp = open(input_path + input_name, "r")
    # inputVal = infp.read()
    # infp.close()

    thread = subprocess.Popen(exe_path + exe_name,
                              stdin=infp,
                              stdout=subprocess.PIPE)
    outfp = open("4-2-out" + str(i) + ".txt", "w")
    outfp.write(str(thread.stdout.read(), encoding="utf-8").replace('\r', ''))
    outfp.close()
