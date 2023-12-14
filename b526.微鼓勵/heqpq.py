import heapq
do_range=[]
PCOUNT,M=[int(input()) for _ in range(2)]#人數,微鼓勵次數
for i in range(M):
    do_range.append(tuple(map(int,input().split(' '))))

heapq.heapify(do_range)#lsit轉heapq

sit=0
def PRINT_STATE(sp='##'):
    # return
    global do_rang,sit
    print(sp,do_range,len(do_range),sit)
while(1):
    LENrange=len(do_range)
    # PRINT_STATE("+")
    if LENrange==1:
        # PRINT_STATE('@')
        last=heapq.heappop(do_range)
        sit+=last[1]-last[0]+1
        break
    elif LENrange>1:
        left=heapq.heappop(do_range)
        right=heapq.heappop(do_range)#把最小的兩項pop出來比較消除。最後再把化簡後的範圍放回來，做到不能再消除
    else:
        break
    #index 0:起點
    #index 1:終點
    L_start=left[0];R_start=right[0]
    L_end=left[1];R_end=right[1]
    #先檢查最左邊範圍是不是只有一點
    if L_start==L_end and L_start<R_start:
        #左cuple內的兩個值相同，對單個人做微鼓勵
        sit+=1
        heapq.heappush(do_range,right)#right沒做到，放回去
        continue
    if L_start==R_start:#起點相同
        if L_end==R_end:#起點和終點都相同，不動作
            continue
        elif L_end<R_end:
            '''left範圍較短一點
            ---
            -----
            '''
            heapq.heappush(do_range,(L_end+1,R_end))#留多出來那段
            # LenM-=1
    elif (L_start<R_start and L_end>R_end): #L覆蓋的範圍比R大，用L-R分成兩塊
        '''
            ------
              --
        '''
#插入被切開不重複的兩段
        heapq.heappush(do_range, (L_start,R_start-1))
        heapq.heappush(do_range, (R_end+1,L_end))
    elif (L_start<R_start and L_end==R_end):#不同起點，相同終點
        '''
            ----
              --
        '''
        heapq.heappush(do_range, (L_start,R_start-1))
        # LenM-=1
    elif (L_start<R_start and L_end<R_end and R_start<L_end):
        '''
            ---
              ----
        '''
        heapq.heappush(do_range, (L_start,R_start-1))
        heapq.heappush(do_range, (L_end+1,R_end))
    else:
        #左右無法消除，把left加進去坐著的人數，right放回去待辦和第三項比較
        sit+=left[1]-left[0]+1
        heapq.heappush(do_range,(R_start,R_end))
#出whille
print(PCOUNT-sit)