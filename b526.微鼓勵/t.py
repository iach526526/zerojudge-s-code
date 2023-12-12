import heapq
do_range=[]
PCOUNT,M=[int(input()) for _ in range(2)]#人數,微鼓勵次數
for i in range(M):
    do_range.append(tuple(map(int,input().split(' '))))

heapq.heapify(do_range)#lsit轉heapq
do_range[0]=do_range[-1]
print(do_range[0])
print(do_range[1])

print(len(do_range))