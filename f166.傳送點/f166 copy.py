N,TARGET,L,R=map(int,input().split())
# ^ n格，目標，每次左/右可移動的步數
local=list(map(int,input().split()))
# ^ 每一格地上傳送點座標

def go(now):
    global local
    if now<0 or now>=N:
        return -1
    else:
        return local[now]
def add_son(ROOT):
    global next_layertemp,L,R
    goL=go(ROOT-L);goR=go(ROOT+R)
    if goL!=-1:
        next_layertemp.add(goL)
    if goR!=-1:
        next_layertemp.add(goR)
Tstep=1#Totalstep:操作次數記數，輸出就要它
now_layerNode=[]
next_layertemp=set()
add_son(0)
while(1):
    # print('List:',now_layerNode,'STEP',Tstep)
    now_layerNode=list(next_layertemp.copy())
    next_layertemp.clear()
    # print('List:',now_layerNode,'STEP',Tstep)
    error=1
    now_layerNode.sort()
    for i in now_layerNode:#判斷這層是否全部為-1(走出去的節點)，若成立，則結束程式
        if i!=-1:
            error=0
            break
    if error:
        print(-1)
        exit()
    while(now_layerNode!=[]):
        if now_layerNode[0]==TARGET:
            print(Tstep)
            exit()
        add_son(now_layerNode[0])#append子樹，放在next_layertemp占存，等等會丟給now_layer執行
        now_layerNode.pop(0)
    
    Tstep+=1