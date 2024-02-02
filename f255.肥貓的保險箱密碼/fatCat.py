
howbits=int(input())
table=[(1,2)]
while(howbits!=0):
    if howbits>table[0][0]:
        #把最大的紀錄起來，下次遇到比它大的就從它對應的值開始左移
        ans=table[0][1] << howbits-table[0][0]
        print(ans)
        table[0]=(ans,howbits)
    else:
        print(1 << howbits)
    howbits=int(input())