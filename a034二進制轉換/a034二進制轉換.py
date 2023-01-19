#這是我寫的十進位轉二進位程式
while True:
    try:
        z=[]
        y=(input('輸入任意數字'))
        y=int(y)
        while True:
       
            if y//2<1:
                if y%2==1:
                    z.append('1')
                break    
            else:
                answer=str(y%2)  #a值是y Mod 2的值，即所求二進位各個位元(最後才做顛倒的動作，使用reverse函式)
                z.append(answer)
                y=y//2 #y值是每次自己的值與2取商數的結果
    except:
        break    
    z.reverse() #顛倒列表順序
    Strz="".join(z) #把z的列表型態換成字串
    print(Strz)