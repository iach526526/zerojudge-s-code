#include <stdio.h>
int GCD(int,int);
int main(){
	int N1,N2;
	while((scanf("%d%d",&N1,&N2))!=EOF)
	{
		printf("%d\n",GCD(N1,N2));
	}

}
int GCD(int a,int b)//輾轉相除法找GCD 
{
	if (a>b)
	{
		int temp=a;
		a=b;
		a=temp;
	}
	int flag=0;
	while(b%a!=0 && a%b!=0)//只要不整除就繼續輾轉相除 
	{
		if (flag==0)
		{
			b=b%a;
			flag=1;
		}
		else if(flag==1){
			a=a%b;
			flag=0 ;
		}
		
		
	}
	switch(flag){
		case 1:
			return b;
		case 0:
			return a;
	}
		
	
}
