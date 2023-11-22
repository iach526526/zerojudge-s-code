def find_next(num,nowINdex,lst):
    while(lst[nowINdex]==num):
        nowINdex+=1
    return nowINdex
PCOUNT,M=[int(input()) for _ in range(2)]#人數,微鼓勵次數
do_range=[]
for i in range(M):
    do_range.append(tuple(map(int,input().split(' '))))
sorted(do_range)#排序微鼓勵區間，希望可以找到重
index_ptr=0
# print(do_range)
LenM=len(do_range)
whileCount=0;range_temper=0
def rmRange(index,count):#給定索引，向右刪除count個元素
     for _ in range(0,count):
        do_range.pop(index)
while(index_ptr<LenM):
     left=do_range[index_ptr];right=do_range[index_ptr+1]#相鄰兩項出來比較
     #index 0:起點
     #index 1:終點
     if left[0]==right[0]:#起點相同
            L_end=left[1];R_end=right[1]
            if L_end>R_end:
                 '''left範圍較長一點
                 -----
                 ---
                 '''
                 rmRange(index_ptr,2)#兩項都刪除，用下面那行取代
                 do_range.insert(index_ptr,(R_end-left[0],R_end))#留多出來那段
            elif L_end<R_end:
                 '''left範圍較短一點
                 ---
                 -----
                 '''
                 rmRange(index_ptr,2)#兩項都刪除，用下面那行取代
                 do_range.insert(index_ptr,(L_end,R_end))#留多出來那段
            elif L_end==R_end:#終點也相同
                 rmRange(index_ptr,2)#兩項都刪除(抵銷)#等於沒做，消除
    elif : #R

            


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