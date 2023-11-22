def find_next(num,nowINdex,lst):
    while(lst[nowINdex]==num):
        nowINdex+=1
    return nowINdex
PCOUNT,M=[int(input()) for _ in range(2)]#人數,微鼓勵次數
do_range=[]
for i in range(M):
    do_range.extend(list(map(int,input().split(' '))))
do_range.sort()
index_ptr=0
# print(do_range)
LenM=len(do_range)
whileCount=0;range_temper=0
while(LenM>0):
    L=do_range.pop(0);R=do_range.pop(-1)
    if whileCount%2==0 :
            range_temper+=R-L+1
    else:
        range_temper-= (R-L+1) 
    #結束，處理迴圈變數
    whileCount+=1
    LenM-=2
print(PCOUNT-range_temper)

'''
while(index_ptr<M):
    index_ptr=find_next(num=do_range[index_ptr],nowINdex=index_ptr,lst=do_range)
'''