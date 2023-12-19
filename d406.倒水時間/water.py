#stack解BFS
def FINDFIRST(arr,col):
    for i in range(col):
        if(arr[0][i]=='1'):
            return i
case=0
while(1):
    try:
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
        WORK=[]#待處理堆疊
        #※  因為開始倒的地方只有 1 個且只在第一列倒，先找出那個座標
        startXP=FINDFIRST(space,M)
        space[0][startXP]=1
        WORK.append((startXP,0,2))#插入第一個
        # TIME=1
        while(WORK!=[]):
            nowX,nowY,TIME=WORK.pop(0)
            # print(nowX,nowY,TIME)
            if (flag==1 and nowY-1>=0 and space[nowY-1][nowX]=='1'):#option:往上走
                WORK.append((nowX,nowY-1,TIME+1))
                space[nowY-1][nowX]=TIME
            if (nowY+1<N and space[nowY+1][nowX]=='1'):#往下走
                WORK.append((nowX,nowY+1,TIME+1))
                space[nowY+1][nowX]=TIME
            if (nowX-1>=0 and space[nowY][nowX-1]=='1'):#往左走
                WORK.append((nowX-1,nowY,TIME+1))
                space[nowY][nowX-1]=TIME
            if (nowX+1<M and space[nowY][nowX+1]=='1'):#往右走
                WORK.append((nowX+1,nowY,TIME+1))
                space[nowY][nowX+1]=TIME
            # TIME+=1
                

        print(f'Case {case}:')
        for row in space:
            count=M
            for col in row:
                if col=="1":#水不能往上流或沒有連通的水管原本的位置要換成0
                    output=0
                else:
                    output=col
                if count==0:
                    print(int(output),end='')
                    count-=1
                else:
                    print(int(output),end=' ')
            print()
    except:
        break