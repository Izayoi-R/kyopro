import subprocess

print("The number of cases you want to generate : ",end="")
num = int(input())
for i in range(1,num+1):
    # inフォルダ内に「1.txt」「2.txt」・・・と作成していく
    # 1-indexedだけど我慢してね。
    name = 'in\\'+str(i)+'.txt'
    # generate.cppをコンパイルしてできたgenerate.exeを実行するコマンド（.exeは省略可）
    subprocess.call("generate > "+name,shell=True)
print("Complete !!")
