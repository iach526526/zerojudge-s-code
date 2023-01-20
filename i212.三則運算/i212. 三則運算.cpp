/*輸入由兩個數字 
 a和b和一個運算符號x組成
數字和運算符號之間有一個空格
 a和b不會有前綴 0
 0<=a,b<=10^10^6
 x包含+-*
 若x=-，則保證a>=b
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
 				//strlen從1開始數 
 				int init_len_a=strlen(a),init_len_b=strlen(b);
 				
//				printf("!%d%d!",strlen(a),strlen(b));
 				if(strlen(a)-strlen(b)>0)//a位數比b多 ，b補0 
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
					add(a,b);//把a、b陣列的開頭餵給函數做相加(因為已經做了顛倒，所以第0項是個位) 
				 }
				 else if(strlen(a)-strlen(b)<0)//b位數比a多 ，a補0 
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
 /*酷炫的小功能*/
void reverse(char *first,char *last,int len)//陣列翻轉(從0項開始到'\0'之前那項)
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
 void reverse_int(int *first,int *last,int len)//陣列翻轉(從0項開始到'\0'之前那項)
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
 void printf_arr(char *arr)//把字元陣列印出
 {
 	int i=0;
	while(arr[i]!='\0')
	{
		printf("%c",arr[i]);
		i++;
	 }
	 printf("\n");
 }
  void printf_int_arr(int *arr)//把數字陣列印出
 {
 	int i=0;
	while(arr[i]!='\0')
	{
		printf("%d",arr[i]);
		i++;
	 }
 }
  /*酷炫的小功能*/
  
  /*加減乘*/ 
 void add(char *aa,char *bb)
 {

	 
	char ans_temp[9999]={'\0'};
 	int i=0,carry=0;//carry:進位
//	printf_arr(aa);
//	printf_arr(bb);
 	while(*(aa+i)!='\0' && *(bb+i)!='\0')
 	{
// 		printf("%d",carry);
		ans_temp[i]=(*(aa+i)-48)+(*(bb+i)-48)+carry+48;
 		carry=0;//加完歸零 
 		if(ans_temp[i]-48>=10)//換成整數型態才能比大小 
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
