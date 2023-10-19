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
    global same_layerNode,L,R
    goL=go(ROOT-L);goR=go(ROOT+R)
    if goL!=-1:
        same_layerNode.append(goL)
    if goR!=-1:
        same_layerNode.append(goR)
Tstep=0#Totalstep:操作次數記數，輸出就要它
same_layerNode=[]
add_son(0)
visted=set()
while(1):
    
    
    # print('List:',same_layerNode,'STEP',Tstep)
    
    for layer in range(2**Tstep):
        print('List:',same_layerNode,'STEP',Tstep)
        
        if same_layerNode==[]:
            print(-1)
            exit()
        if same_layerNode[0]==TARGET:
            print(Tstep+1)
            exit()
            
        if layer%2==0 and not(same_layerNode[0] in visted):
            add_son(same_layerNode[0])#從左到右append子樹
            visted.add(same_layerNode[0])#放入已造訪清單，之後若有其他節點和清單內重複可以不用往下走，就是個死路
            same_layerNode.pop(0)
        else:
            same_layerNode.pop(0)
    Tstep+=1
