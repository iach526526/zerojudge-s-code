while(1):
    try:
        n=int(input())
        LIST=list(map(int,input().split()))
        L1=[];L2=[];L3=[];L4=[];L5=[];L6=[];L7=[];L8=[];L9=[];L0=[]
        for i in LIST:
            if i%10==0:
                L0.append(i)
            elif i%10==1:
                L1.append(i)
            elif i%10==2:
                L2.append(i)
            elif i%10==3:
                L3.append(i)
            elif i%10==4:
                L4.append(i)
            elif i%10==5:
                L5.append(i)
            elif i%10==6:
                L6.append(i)
            elif i%10==7:
                L7.append(i)
            elif i%10==8:
                L8.append(i)
            elif i%10==9:
                L9.append(i)
        L0.sort(reverse=True);L1.sort(reverse=True);L2.sort(reverse=True);
        L3.sort(reverse=True);L4.sort(reverse=True);L5.sort(reverse=True);
        L6.sort(reverse=True);L7.sort(reverse=True);L8.sort(reverse=True);
        L9.sort(reverse=True)
        ans = L0 + L1 + L2 + L3 + L4 + L5 + L6 + L7 + L8 +L9
        STR_ans=''
        for i in ans:
            STR_ans+=str(i)+' '
        print(STR_ans)
    except:
        break