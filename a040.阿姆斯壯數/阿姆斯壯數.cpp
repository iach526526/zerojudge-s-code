#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
//��J�@�@��]�t��ӼƦrn, m(n<m, n>0, m<=1000000)�A
//�N��Ҧ��M�� armstrong number ���d��
int Armstrong(int);
int len(int);
int main()
{	int n,m,i,flag=0;
	scanf("%d%d",&n,&m);
	for(i=n;i<=m;i++)
	{
		if(i==Armstrong(i))
		{
			printf("%d ",i);
			flag=1;
		}
		
		
	}
	if(flag==0)
	{
		printf("none");
	}
//	printf("%d",len(n));
	
	
}
int Armstrong(int x)
{
	int copy_x=x,a,sigma=0,p;
	p=len(x);
	do{
		a=x%10;
		sigma=sigma+pow(a,p);
		x=x/10;
	}while(x>0);
//	if (copy_x==sigma){
//		printf("%d ",copy_x);
//	}
	return sigma;
	
	
}
int len(int y)
{
	int i=0;
	do{
		i++;
		
		y=y/10;
	}while(y>0);
	
	return i;
}


