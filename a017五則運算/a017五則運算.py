while True:
    try:
       x=input('輸入要計算的運算式').replace('/','//') #把除號換成取商數，使運算的結果皆為整數
    except:
        break
    
    print(eval(x))