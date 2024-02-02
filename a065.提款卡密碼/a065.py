Secret=input()
for index in range(len(Secret)-1):
    print(abs(ord(Secret[index+1])-ord(Secret[index])),end='')
    