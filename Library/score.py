import os

def score(in_file,out_file):
    in_file = open(in_file,mode='r')
    input = in_file.readline
    out_file = open(out_file,mode='r')
    output = out_file.readline
    # ここから下にスコア算出のコードを書く
    # 入力ケースはinput()で1行受け取れる
    # 出力ケースはoutput()で1行受け取れる
    # 不適な出力ケースの場合、WAとして負数を返す
    
    res = -1
    return res 


print("Calculate all cases?(y/n): ",end="")
s=input()
max_score = 10**15 # 1ケース当たりの最高得点
ac=0 # ACケース数
wa=0 # WAケース数（WAは便宜的に負のスコアとする）
sum=0 # 合計得点
if s=='y' or s=='Y' or s=='Yes' or s=='yes' or s=='YES':
    case_num=1
    while True:
        in_file = "in\\"+str(case_num)+".txt"
        out_file = "out\\"+str(case_num)+".txt"
        if os.path.isfile(in_file) and os.path.isfile(out_file):
            res = score(in_file,out_file)
            if res<0:
                wa += 1
            else:
                ac += 1
                sum += res
        else:
            break
    print("\n"+str(ac+wa)+" cases are calculated.")
    print("AC      : "+str(ac))
    print("WA      : "+str(wa))
    print("Score   : "+str(sum))
    print("Score(%): "+str(100.0*sum/(ac+wa)/max_score if ac+wa>0 else -1))
else:
    print("How many cases do you calculate?: ",end="")
    num=int(input())
    for i in range(1,num+1):
        in_file = "in\\"+str(i)+".txt"
        out_file = "out\\"+str(i)+".txt"
        if os.path.isfile(in_file) and os.path.isfile(out_file):
            res = score(in_file,out_file)
            if res<0:
                wa += 1
            else:
                ac += 1
                sum += res
            print("\nCase "+str(i)+": "+("WA" if res<0 else "AC"))
            print("    Score: "+str((max(-1,res))))
            print("    Score(%): "+str(100.0*res/max_score if res>=0 else -1))
        else:
            break
    print("\n"+str(ac+wa)+" cases are calculated.")
    print("AC      : "+str(ac))
    print("WA      : "+str(wa))
    print("Score   : "+str(sum))
    print("Score(%): "+str(100.0*sum/(ac+wa)/max_score if ac+wa>0 else -1))