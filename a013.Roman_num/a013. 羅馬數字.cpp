#include <stdio.h>
#include <math.h>
#define arrsize 99
/* 弄ㄢタ俱计礛块ㄢ计畉荡癸
┮Τ计常ゲ斗霉皑计ㄓボτ硈尿才腹瞷
ゲ斗ノ搭猭砏玥ㄓて虏ぇ*/ 
 
int roman_to_dec(char);//р霉皑计㎝10秈癸莱(switch) 
int translate_to_real_dec(int *);//(传Θ10秈霉皑计皚)
int chang_Roman_num(int);
int main()
{
	char num1[arrsize]={'\0'},num2[arrsize]={'\0'};
	while(scanf("%s",num1)!=EOF)
	{
		if(num1[0]=='#')
		{
			return 0;
		}
		scanf("%s",num2);
		
		int i=0;//ǐ砐皚–index 
		int dec_num1[arrsize]={'\0'},dec_sum1=0;//dec_num皚ノㄓ纗–霉皑计皚锣Θ10秈计 
		int dec_num2[arrsize]={'\0'},dec_sum2=0;
		/*だр块ㄢ舱代戈传Θ10秈ǐ砐じ皚\0*/
		while(num1[i]!='\0')
		{
			dec_num1[i]=roman_to_dec(num1[i]);
			i++;
		}
		i=0;
		while(num2[i]!='\0')
		{
			dec_num2[i]=roman_to_dec(num2[i]);
			i++;
		}
		/*だр块ㄢ舱代戈传Θ10秈ǐ砐じ皚\0*/
		dec_sum1=translate_to_real_dec(dec_num1);
		dec_sum2=translate_to_real_dec(dec_num2);
		int ans_dec=abs(dec_sum1-dec_sum2);
		if(ans_dec==0)
		{
			printf("ZERO\n");
		}
		else
		{
			chang_Roman_num(ans_dec);
			printf("\n");
		}
//		printf("%d\n",ans_dec);
	}
 }
 ///////////祘Α挡////////////////////// 
 int translate_to_real_dec(int *ptr_dec_sum)
 {
 	int i=0,total=0;
	 while(*(ptr_dec_sum+i)!='\0')
		{
			if(*(ptr_dec_sum+i)<*(ptr_dec_sum+i+1))//耕霉皑计オ娩癘耕霉皑计ボ计搭计
			{
				total+=abs(*(ptr_dec_sum+i)-*(ptr_dec_sum+i+1));
				i+=2;
			}
			else
			{
				total+=*(ptr_dec_sum+i);
				i++;
			}
		}
	return total;
 }
 //霉皑计ボ疭ㄒ:计絏程硈尿瞷Ω40琌XLぃノ⒙⒙⒙⒙
 int chang_Roman_num(int digits_dec)
 {
 	int copy_digits_dec=digits_dec;
 	// M:1000 =>计 
 	while((digits_dec/1000)>=1)//块代戈穦<4000杠...碞块帮M!
 	{
 		digits_dec-=1000;
 		printf("M");
	 }
	//C:100 =>κ计 
	int large_than100=0;
	while(digits_dec/100>=1)
 	{
 		large_than100++;
 		digits_dec-=100;
	 }
 	switch(large_than100)
 		{
	 		case 9://κ计:9
	 			printf("CM");
	 			break;
	 		case 8://κ计:8
	 			printf("DCCC");
	 			break;
	 		case 7://κ计:7
	 			printf("DCC");
	 			break;
	 		case 6://κ计:6
	 			printf("DC");
	 			break;
	 		case 5://κ计:5 
	 			printf("D");
	 			break;
	 		case 4://κ计:4 
	 			printf("CD");
	 			break;
	 		case 3://κ计:3 
	 			printf("CCC");
	 			break;
	 		case 2://κ计:2 
	 			printf("CC");
	 			break;
	 		case 1://κ计:4 
	 			printf("C");
	 			break;
	 		default:
	 			break;
		 }
	 
	 //计 
	int large_than10=0;
	 while(digits_dec/10>=1)
 	{
 		large_than10++;
 		digits_dec-=10;
	 }
	switch(large_than10)
	{
		case 9://计:9
 			printf("XC");
 			break;
 		case 8://计:8
 			printf("LXXX");
 			break;
 		case 7://计:7
 			printf("LXX");
 			break;
 		case 6://计:6
 			printf("LX");
 			break;
 		case 5://计:5 
 			printf("L");
 			break;
 		case 4://计:4 
 			printf("XL");
 			break;
 		case 3://计:3
 			printf("XXX");
 			break;
 		case 2://计:2 
 			printf("XX");
 			break;
 		case 1://计:1 
 			printf("X");
 			break;
 		default:
 			break;
	}
	// 
	//计 
	int large_than1=0;
	 while(digits_dec!=0)
 	{
 		large_than1++;
 		digits_dec-=1;
	 }
	switch(large_than1)
	{
		case 9://计:9
 			printf("IX");
 			break;
 		case 8://计:8
 			printf("VIII");
 			break;
 		case 7://计:7
 			printf("VII");
 			break;
 		case 6://计:6
 			printf("VI");
 			break;
 		case 5://计:5 
 			printf("V");
 			break;
 		case 4://计:4 
 			printf("IV");
 			break;
 		case 3://计:3
 			printf("III");
 			break;
 		case 2://计:2
 			printf("II");
 			break;
 		case 1://计:1
 			printf("I");
 			break;
 		default:
 			break;
	}
 }
 int roman_to_dec(char C)//霉皑计㎝10秈癸莱 
 {
 	switch(C)
		{
			case 'M':
				return 1000;
			case 'D':
				return 500;
			case 'C':
				return 100;
			case 'L':
				return 50;
			case 'X':
				return 10;
			case 'V':
				return 5;
			case 'I':
				return 1;
			default:
				return 0;
		}
 }
