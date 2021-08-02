import subprocess

print("The number of cases you want to generate : ",end="")
num = int(input())
for i in range(1,num+1):
    name = 'in\\'+str(i)+'.txt'
    subprocess.call("generate > "+name,shell=True)
print("Complete !!")
