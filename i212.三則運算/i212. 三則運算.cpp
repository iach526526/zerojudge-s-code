/*��J�Ѩ�ӼƦr 
 a�Mb�M�@�ӹB��Ÿ�x�զ�
�Ʀr�M�B��Ÿ��������@�ӪŮ�
 a�Mb���|���e�� 0
 0<=a,b<=10^10^6
 x�]�t+-*
 �Yx=-�A�h�O��a>=b
 */ 
#include <stdio.h>
#include <string.h>
void reverse(char *,char *,int);
void printf_arr(char *);
void printf_int_arr(int *);
void add(char *,char *);
 int main()
 {
 	char a[9999]={'\0'},b[9999]={'\0'},op[2];
 	while(scanf("%s%s%s",a,op,b)!=EOF)
 	{
		switch(op[0])
 		{
 			case '+':
 				//strlen�q1�}�l�� 
 				int init_len_a=strlen(a),init_len_b=strlen(b);
 				
//				printf("!%d%d!",strlen(a),strlen(b));
 				if(strlen(a)-strlen(b)>0)//a��Ƥ�b�h �Ab��0 
 				{
 					int j;
 					for(j=0;j<init_len_a-init_len_b;)
 					{
 						b[strlen(b)]='0';
						j++;
					 }
//					printf("!%d%d!",strlen(a),strlen(b));
//					printf_arr(a);
//	 				printf_arr(b);
	 				reverse(&a[0],&a[strlen(a)-1],strlen(a));
//	 				reverse(&b[0],&b[strlen(b)-1],strlen(b));
//	 				reverse(&b[0],&b[strlen(b)-1],strlen(b));
					add(a,b);
				 }else if(strlen(a)-strlen(b)==0)
				 {
				 	reverse(&a[0],&a[strlen(a)-1],strlen(a));
	 				reverse(&b[0],&b[strlen(b)-1],strlen(b));
					add(a,b);//��a�Bb�}�C���}�Y������ư��ۥ[(�]���w�g���F�A�ˡA�ҥH��0���O�Ӧ�) 
				 }
				 else if(strlen(a)-strlen(b)<0)//b��Ƥ�a�h �Aa��0 
				 {
				 	int j;
 					for(j=0;j<init_len_b-init_len_a;)
 					{
 						a[strlen(b)]='0';
						j++;
					 }
//					printf("!%d%d!",strlen(a),strlen(b));
//					printf_arr(a);
//	 				printf_arr(b);
	 				//reverse(&a[0],&a[strlen(a)-1],strlen(a));
	 				reverse(&b[0],&b[strlen(b)-1],strlen(b));
//	 				reverse(&b[0],&b[strlen(b)-1],strlen(b));
					add(a,b);
				 }
 				break;
 			
		 }
//		a[9999]={'\0'};b[9999]={'\0'};
	 }
 }
 /*�Ŭ����p�\��*/
void reverse(char *first,char *last,int len)//�}�C½��(�q0���}�l��'\0'���e����)
 {
 	int i;
	 for(i=0;i<=len%2;i++)
	 {
	 	char temp;
	 	temp=*(first+i);
	 	*(first+i)=*(last-i);
	 	*(last-i)=temp;
	 }
 }
 void reverse_int(int *first,int *last,int len)//�}�C½��(�q0���}�l��'\0'���e����)
 {
 	int i;
	 for(i=0;i<=len%2;i++)
	 {
	 	char temp;
	 	temp=*(first+i);
	 	*(first+i)=*(last-i);
	 	*(last-i)=temp;
	 }
 }
 void printf_arr(char *arr)//��r���}�C�L�X
 {
 	int i=0;
	while(arr[i]!='\0')
	{
		printf("%c",arr[i]);
		i++;
	 }
	 printf("\n");
 }
  void printf_int_arr(int *arr)//��Ʀr�}�C�L�X
 {
 	int i=0;
	while(arr[i]!='\0')
	{
		printf("%d",arr[i]);
		i++;
	 }
 }
  /*�Ŭ����p�\��*/
  
  /*�[�*/ 
 void add(char *aa,char *bb)
 {

	 
	char ans_temp[9999]={'\0'};
 	int i=0,carry=0;//carry:�i��
//	printf_arr(aa);
//	printf_arr(bb);
 	while(*(aa+i)!='\0' && *(bb+i)!='\0')
 	{
// 		printf("%d",carry);
		ans_temp[i]=(*(aa+i)-48)+(*(bb+i)-48)+carry+48;
 		carry=0;//�[���k�s 
 		if(ans_temp[i]-48>=10)//������ƫ��A�~���j�p 
 		{
 			
			ans_temp[i]-=10;
 			carry+=1;
// 			printf("%d",carry);
		}
		 i++;
	 }
//	printf_arr(ans_temp);
	int len_ans=strlen(ans_temp);
	reverse(&ans_temp[0],&ans_temp[len_ans-1],len_ans);
	printf_arr(ans_temp);
 }
