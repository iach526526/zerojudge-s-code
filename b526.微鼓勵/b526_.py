import heapq
do_range=[]
def rmRange(lst,index,count):#給定索引，向右刪除count個元素
    # PRINT_STATE("-")
    for _ in range(0,count):
        # print('index+1',do_range)
        lst.pop(index)
PCOUNT,M=[int(input()) for _ in range(2)]#人數,微鼓勵次數
for i in range(M):
    do_range.append(tuple(map(int,input().split(' '))))

heapq.heapify(do_range)#lsit轉heapq
# exit()
index_ptr=0
do_range.sort()#排序微鼓勵區間元組
LenM=M
cte=1
def PRINT_STATE(sp='##'):
    # return
    global do_range,index_ptr,LenM
    print(sp,do_range,len(do_range),LenM,index_ptr)
while(1):
    # PRINT_STATE("!")
    if (index_ptr>=LenM-1) or LenM<=1:
        PRINT_STATE('@')
        break
    else:
        left=do_range[index_ptr];right=do_range[index_ptr+1]#相鄰兩項出來比較
    #index 0:起點
    #index 1:終點
    L_start=left[0];R_start=right[0]
    L_end=left[1];R_end=right[1]
    if L_start==R_start:#起點相同
        cte=1
        if L_end==R_end:#起點和終點都相同
            rmRange(do_range,index_ptr,2)#兩項都刪除(抵銷)#等於沒做，消除
            LenM-=2
        else:
            '''left範圍較短一點
            ---
            -----
            '''
            rmRange(do_range,index_ptr,2)#兩項都刪除，用下面那行取代
            do_range.insert(index_ptr,(L_end+1,R_end))#留多出來那段
            LenM-=1
    elif (L_start<R_start and L_end>R_end): #L覆蓋的範圍比R大，用L-R分成兩塊
        '''
            ------
              --
        '''
        cte=1
        rmRange(do_range,index_ptr,2)#兩項都刪除，用下面那行取代
        do_range.insert(index_ptr,(L_start,R_start-1))#插入被切開不重複的兩段
        do_range.insert(index_ptr,(R_end+1,L_end))#插入被切開不重複的兩段!!!!
    elif (L_start<R_start and L_end==R_end):#不同起點，相同終點
        '''
            ----
              --
        '''
        cte=1
        rmRange(do_range,index_ptr,2)#兩項都刪除，用下面那行取代
        do_range.insert(index_ptr,(L_start,R_start-1))#插入被切開不重複的部分
        LenM-=1
    else:#無法消除
        index_ptr+=1
    if cte==1 and index_ptr>=LenM-1:
        do_range.sort()
        index_ptr=0
        cte=0
    elif (cte==0 and index_ptr>=LenM-1):
        PRINT_STATE("cte=0")
        break
#出whille
# print(",",do_range)
# PRINT_STATE("@")
sit=0
for tern in do_range:
    sit+=tern[1]-tern[0]+1
print(PCOUNT-sit)