#include <stdio.h>
#include <math.h>
#define arrsize 99
/* 讀入兩個正整數，然後輸出兩個數字差的絕對值。
所有的數字都必須以羅馬數字來表示。而連續四個相同符號出現時，
必須用減法規則來化簡之。*/ 
 
int roman_to_dec(char);//把羅馬數字和10進制對應(switch) 
int translate_to_real_dec(int *);//(換成10進制的羅馬數字陣列位址)
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
		
		int i=0;//走訪陣列每個index 
		int dec_num1[arrsize]={'\0'},dec_sum1=0;//dec_num陣列用來儲存每個羅馬數字陣列轉成10進制數字的值 
		int dec_num2[arrsize]={'\0'},dec_sum2=0;
		/*分別把輸入的兩組測資換成10進制，走訪字元陣列直到\0*/
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
		/*分別把輸入的兩組測資換成10進制，走訪字元陣列直到\0*/
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
 ///////////主程式結束////////////////////// 
 int translate_to_real_dec(int *ptr_dec_sum)
 {
 	int i=0,total=0;
	 while(*(ptr_dec_sum+i)!='\0')
		{
			if(*(ptr_dec_sum+i)<*(ptr_dec_sum+i+1))//在較大的羅馬數字的左邊記上較小的羅馬數字，表示大數字減小數字。
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
 //羅馬數字表示特例:同一數碼最多連續出現三次，如40是XL，不用ⅩⅩⅩⅩ。
 int chang_Roman_num(int digits_dec)
 {
 	int copy_digits_dec=digits_dec;
 	// M:1000 =>千位數 
 	while((digits_dec/1000)>=1)//輸入測資會<4000，大於的話...就輸出一堆M吧!
 	{
 		digits_dec-=1000;
 		printf("M");
	 }
	//C:100 =>百位數 
	int large_than100=0;
	while(digits_dec/100>=1)
 	{
 		large_than100++;
 		digits_dec-=100;
	 }
 	switch(large_than100)
 		{
	 		case 9://百位數字:9
	 			printf("CM");
	 			break;
	 		case 8://百位數字:8
	 			printf("DCCC");
	 			break;
	 		case 7://百位數字:7
	 			printf("DCC");
	 			break;
	 		case 6://百位數字:6
	 			printf("DC");
	 			break;
	 		case 5://百位數字:5 
	 			printf("D");
	 			break;
	 		case 4://百位數字:4 
	 			printf("CD");
	 			break;
	 		case 3://百位數字:3 
	 			printf("CCC");
	 			break;
	 		case 2://百位數字:2 
	 			printf("CC");
	 			break;
	 		case 1://百位數字:4 
	 			printf("C");
	 			break;
	 		default:
	 			break;
		 }
	 
	 //十位數 
	int large_than10=0;
	 while(digits_dec/10>=1)
 	{
 		large_than10++;
 		digits_dec-=10;
	 }
	switch(large_than10)
	{
		case 9://十位數字:9
 			printf("XC");
 			break;
 		case 8://十位數字:8
 			printf("LXXX");
 			break;
 		case 7://十位數字:7
 			printf("LXX");
 			break;
 		case 6://十位數字:6
 			printf("LX");
 			break;
 		case 5://十位數字:5 
 			printf("L");
 			break;
 		case 4://十位數字:4 
 			printf("XL");
 			break;
 		case 3://十位數字:3
 			printf("XXX");
 			break;
 		case 2://十位數字:2 
 			printf("XX");
 			break;
 		case 1://十位數字:1 
 			printf("X");
 			break;
 		default:
 			break;
	}
	// 
	//個位數 
	int large_than1=0;
	 while(digits_dec!=0)
 	{
 		large_than1++;
 		digits_dec-=1;
	 }
	switch(large_than1)
	{
		case 9://個位數字:9
 			printf("IX");
 			break;
 		case 8://個位數字:8
 			printf("VIII");
 			break;
 		case 7://個位數字:7
 			printf("VII");
 			break;
 		case 6://個位數字:6
 			printf("VI");
 			break;
 		case 5://個位數字:5 
 			printf("V");
 			break;
 		case 4://個位數字:4 
 			printf("IV");
 			break;
 		case 3://個位數字:3
 			printf("III");
 			break;
 		case 2://個位數字:2
 			printf("II");
 			break;
 		case 1://個位數字:1
 			printf("I");
 			break;
 		default:
 			break;
	}
 }
 int roman_to_dec(char C)//羅馬數字和10進制對應 
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
