#一直要你輸入值給他判斷閏平年
while True:
	try:
		x=int(input('輸入要判斷的年份'))
	except:
		break
	if x%4==0 and x%100!=0 or x%400==0:
			print('閏年')
	else:
			print('平年')