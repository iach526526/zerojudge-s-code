#include <stdio.h>
#include <math.h>
int main()
{
	
	int a,b,c,x1,x2,root1,root2;
	scanf("%d%d%d",&a,&b,&c);
	if (b*b-(4*a*c)<0)
	{
		printf("No real root");
	}
	x1=-b+pow(b*b-(4*a*c),0.5);
	x2=-b-pow(b*b-(4*a*c),0.5);
	if (b*b-(4*a*c)==0)
	{
		printf("Two same roots x=%d",x1/(2*a));
	}
	
	if (b*b-(4*a*c)>0)
	{
		root1=x1/2*a;
		root2=x2/2*a;
		printf("Two different roots x1=%d , x2=%d",root1,root2);
	}
	
	
	
	return 0;
 } 
