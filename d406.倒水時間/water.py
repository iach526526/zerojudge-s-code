
N,M=0,0
#遞迴解BFS
def bfs(arr,flag,nowT,x=0,y=0):
    global N,M
    if(arr[y][x]=='0'):
        return
    arr[y][x]=str(nowT)
    #判斷下、右、左
    if y+1<N and arr[y+1][x]=='1':
        bfs(arr,flag,nowT+1,x,y+1)
    if x+1<M and arr[y][x+1]=='1':
        bfs(arr,flag,nowT+1,x+1,y)
    if x-1>=0:
        if arr[y][x-1]=='1':
            bfs(arr,flag,nowT+1,x-1,y)
    if flag==1 and y-1>0:
        if arr[y-1][x]=='1':
            bfs(arr,flag,nowT+1,x,y-1)
    if flag==1 and y-1>0:
        if arr[y-1][x]=='1':
            bfs(arr,flag,nowT+1,x,y-1)
    return
        
        


case=0
# while(1):
#     try:
case+=1
flag=int(input())
N,M=map(int,input().split(' '))
'''
M
|‾ ‾ |
N|    |
|    |
'''
space=[]#放置水管的空間(二維)
for i in range(N):
    space.append(input().split(' '))
for col in range(M):
    if space[0][col]=='1':
        # space[0][col]=TIME
        bfs(space,flag,1,col,0)
print(f'Case {case}:')
for row in space:
    count=0
    for col in row:
        if count==0:
            print(int(col),end='')
            count+=1
        else:
            print(' ',int(col),end='')
    print()
    # except:
    #     print("error")
    #     break