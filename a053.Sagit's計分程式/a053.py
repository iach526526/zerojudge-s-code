while(1):
    try:
        n=int(input())
        if(n>=0 and n<=10):
            print(6*n)
        elif(n>10 and n<=20):
            print(60+2*(n-10))
        elif(n>20 and n<=40):
            print(80+(n-20))
        elif(n>40):
            print('100')
    except:
        break