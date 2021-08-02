import subprocess
import os

print("Do you want to check all cases?(y/n) :",end="")
s=input()
if s=='Y' or s=='y' or s=='Yes' or s=='YES':
    i=1
    while True:
        in_file = 'in\\'+str(i)+'.txt'
        out_file = 'out\\'+str(i)+'.txt'
        if os.path.isfile(in_file):
            #print(in_file+" exists.")
            subprocess.call("run < "+in_file+" > "+out_file,shell=True)
        else:
            break
        i += 1
else:
    print("The number of cases you want to check :",end="")
    num = int(input())
    for i in range(1,num+1):
        in_file = 'in\\'+str(i)+'.txt'
        out_file = 'out\\'+str(i)+'.txt'
        if os.path.isfile(in_file):
            print(in_file+" exists.")
            subprocess.call("run < "+in_file+" > "+out_file,shell=True)
        else:
            break

