x=str.split((input('輸入:出生 月_日'))) #5 26 即5/26日
M=int(x[0])
D=int(x[1])
S=(M*2+D)%3
if S==0:
    print("普通")

if S==1:
    print("吉")

if S==2:
    print("大吉")