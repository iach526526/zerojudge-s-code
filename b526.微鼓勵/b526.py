PCOUNT,M=[int(input()) for _ in range(2)]#人數,微鼓勵次數
do_range=[]
for i in range(M):
    do_range.append(tuple(map(int,input().split(' '))))
# M相當於len(do_range)

#first,all peppel are standing
PersonState=[1]*PCOUNT
for Mindex in range(M):#每筆微鼓勵
    for position in range(do_range[Mindex][0],do_range[Mindex][1]+1):#跑每次微鼓勵區間內值的改變
        PersonState[position-1]^=1
        #position-1 because index比數數少1

standC=0
for status in PersonState:
    if status==1:
        standC+=1
print(standC)