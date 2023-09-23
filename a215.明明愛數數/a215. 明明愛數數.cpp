#include <stdio.h>
int main()
{
	int m,n;
	while((scanf("%d%d",&n,&m))!=EOF)
	{
		int sum=0,count=0;
		do 
		{
			sum+=(n+count);
			count++;
		 }while(sum<=m);
		 printf("%d\n",count);
	 } 
	 return 0;
 } 
