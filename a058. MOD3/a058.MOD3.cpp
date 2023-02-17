//給你n個數字，請你輸出3k、3k+1、3k+2的數各有幾個
#include <stdio.h>
int main()
{
	
	int n,i,can_mod3=0,mod3_ret1=0,mod3_ret2=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		int num;
		scanf("%d",&num);
		if(num%3==0)
			can_mod3++;
		else if(num%3==1)
			mod3_ret1++;
		else if(num%3==2)
			mod3_ret2++;
		else
			return 0;
	}
	printf("%d %d %d",can_mod3,mod3_ret1,mod3_ret2);
}  
