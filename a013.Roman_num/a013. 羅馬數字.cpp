#include <stdio.h>
#include <math.h>
#define arrsize 99
/* Ū�J��ӥ���ơA�M���X��ӼƦr�t������ȡC
�Ҧ����Ʀr�������Hù���Ʀr�Ӫ�ܡC�ӳs��|�ӬۦP�Ÿ��X�{�ɡA
�����δ�k�W�h�Ӥ�²���C*/ 
 
int roman_to_dec(char);//��ù���Ʀr�M10�i�����(switch) 
int translate_to_real_dec(int *);//(����10�i�ù���Ʀr�}�C��})
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
		
		int i=0;//���X�}�C�C��index 
		int dec_num1[arrsize]={'\0'},dec_sum1=0;//dec_num�}�C�Ψ��x�s�C��ù���Ʀr�}�C�ন10�i��Ʀr���� 
		int dec_num2[arrsize]={'\0'},dec_sum2=0;
		/*���O���J����մ��괫��10�i��A���X�r���}�C����\0*/
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
		/*���O���J����մ��괫��10�i��A���X�r���}�C����\0*/
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
 ///////////�D�{������////////////////////// 
 int translate_to_real_dec(int *ptr_dec_sum)
 {
 	int i=0,total=0;
	 while(*(ptr_dec_sum+i)!='\0')
		{
			if(*(ptr_dec_sum+i)<*(ptr_dec_sum+i+1))//�b���j��ù���Ʀr������O�W���p��ù���Ʀr�A��ܤj�Ʀr��p�Ʀr�C
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
 //ù���Ʀr��ܯS��:�P�@�ƽX�̦h�s��X�{�T���A�p40�OXL�A���΢¢¢¢¡C
 int chang_Roman_num(int digits_dec)
 {
 	int copy_digits_dec=digits_dec;
 	// M:1000 =>�d��� 
 	while((digits_dec/1000)>=1)//��J����|<4000�A�j�󪺸�...�N��X�@��M�a!
 	{
 		digits_dec-=1000;
 		printf("M");
	 }
	//C:100 =>�ʦ�� 
	int large_than100=0;
	while(digits_dec/100>=1)
 	{
 		large_than100++;
 		digits_dec-=100;
	 }
 	switch(large_than100)
 		{
	 		case 9://�ʦ�Ʀr:9
	 			printf("CM");
	 			break;
	 		case 8://�ʦ�Ʀr:8
	 			printf("DCCC");
	 			break;
	 		case 7://�ʦ�Ʀr:7
	 			printf("DCC");
	 			break;
	 		case 6://�ʦ�Ʀr:6
	 			printf("DC");
	 			break;
	 		case 5://�ʦ�Ʀr:5 
	 			printf("D");
	 			break;
	 		case 4://�ʦ�Ʀr:4 
	 			printf("CD");
	 			break;
	 		case 3://�ʦ�Ʀr:3 
	 			printf("CCC");
	 			break;
	 		case 2://�ʦ�Ʀr:2 
	 			printf("CC");
	 			break;
	 		case 1://�ʦ�Ʀr:4 
	 			printf("C");
	 			break;
	 		default:
	 			break;
		 }
	 
	 //�Q��� 
	int large_than10=0;
	 while(digits_dec/10>=1)
 	{
 		large_than10++;
 		digits_dec-=10;
	 }
	switch(large_than10)
	{
		case 9://�Q��Ʀr:9
 			printf("XC");
 			break;
 		case 8://�Q��Ʀr:8
 			printf("LXXX");
 			break;
 		case 7://�Q��Ʀr:7
 			printf("LXX");
 			break;
 		case 6://�Q��Ʀr:6
 			printf("LX");
 			break;
 		case 5://�Q��Ʀr:5 
 			printf("L");
 			break;
 		case 4://�Q��Ʀr:4 
 			printf("XL");
 			break;
 		case 3://�Q��Ʀr:3
 			printf("XXX");
 			break;
 		case 2://�Q��Ʀr:2 
 			printf("XX");
 			break;
 		case 1://�Q��Ʀr:1 
 			printf("X");
 			break;
 		default:
 			break;
	}
	// 
	//�Ӧ�� 
	int large_than1=0;
	 while(digits_dec!=0)
 	{
 		large_than1++;
 		digits_dec-=1;
	 }
	switch(large_than1)
	{
		case 9://�Ӧ�Ʀr:9
 			printf("IX");
 			break;
 		case 8://�Ӧ�Ʀr:8
 			printf("VIII");
 			break;
 		case 7://�Ӧ�Ʀr:7
 			printf("VII");
 			break;
 		case 6://�Ӧ�Ʀr:6
 			printf("VI");
 			break;
 		case 5://�Ӧ�Ʀr:5 
 			printf("V");
 			break;
 		case 4://�Ӧ�Ʀr:4 
 			printf("IV");
 			break;
 		case 3://�Ӧ�Ʀr:3
 			printf("III");
 			break;
 		case 2://�Ӧ�Ʀr:2
 			printf("II");
 			break;
 		case 1://�Ӧ�Ʀr:1
 			printf("I");
 			break;
 		default:
 			break;
	}
 }
 int roman_to_dec(char C)//ù���Ʀr�M10�i����� 
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
