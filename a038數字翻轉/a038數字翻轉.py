x=(input())
y=''
for i in range (len(x),0,-1):
    y=y + x[i-1]
print(int(y))
    