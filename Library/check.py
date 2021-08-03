import subprocess
import os

print("Do you want to check all cases?(y/n) :",end="")
s=input()
if s=='Y' or s=='y' or s=='Yes' or s=='YES':
    i=1
    while True:
        # // in/outフォルダの名前をhogeフォルダに変更した場合は"hoge\\～"に変更する
        in_file = 'in\\'+str(i)+'.txt'
        out_file = 'out\\'+str(i)+'.txt'
        if os.path.isfile(in_file):
            # mainとなる実行ファイルがrun.exeじゃなくてhoge.exeの場合、"run < " -> "hoge < "に変更
            subprocess.call("run < "+in_file+" > "+out_file,shell=True)
            if i%10==0:
                print(str(i)+" cases is done.")
        else:
            break
        i += 1
else:
    print("The number of cases you want to check :",end="")
    num = int(input())
    for i in range(1,num+1):
        # // in/outフォルダの名前をhogeフォルダに変更した場合は"hoge\\～"に変更する
        in_file = 'in\\'+str(i)+'.txt'
        out_file = 'out\\'+str(i)+'.txt'
        if os.path.isfile(in_file):
            # mainとなる実行ファイルがrun.exeじゃなくてhoge.exeの場合、"run < " -> "hoge < "に変更
            subprocess.call("run < "+in_file+" > "+out_file,shell=True)
        else:
            break

