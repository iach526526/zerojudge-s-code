#include <stdio.h>
#include <stdlib.h>
void swap(int *,int *);
int main()
{
	int how_many;
	scanf("%d",&how_many);//�ǥͼƶq 
	int *student_ptr=(int *)malloc(sizeof(int)*how_many);//student_ptr�ǥͦ��Z 
	int count=0;
	while(scanf("%d",(student_ptr+count))!=EOF && count<how_many-1)
	{count++;}
	int i=0,j=0;
	for(i=0;i<how_many-1;i++)
	{
		for(j=0;j<how_many-i-1;j++)
		{
			if(*(student_ptr+j) > *(student_ptr+j+1))
			{
				swap((student_ptr+j),(student_ptr+j+1));
			}
		}
	}
	int allover60=1,less_than60_max,more_than60_min=-1,not_allover60=1;
	for(j=0;j<=count;j++)//��ƧǹL�����Ū�@����X(�Ĥ@��)�ç�X�̰����ή���ơA�p�G���Ƥή�ɡAallover60=1�F 
	{
		if(*(student_ptr+j)<60)
		{
			less_than60_max=*(student_ptr+j);//�w�g�ƧǡA�C���٦��ŦX����i�H�������N
			allover60=0;//�S�����Ƥή檺�аO 
		}
		else
		{
			if(more_than60_min<*(student_ptr+j))
			{
				if(not_allover60!=0)
					more_than60_min=*(student_ptr+j);//��ܳo�O�Ĥ@��Ū��(�γ̧C)���ή榨�Z 
				not_allover60=0;//�S�������ή檺�аO 
			}
		}
		if(j==0)
			printf("%d",*(student_ptr+j));
		else
			printf(" %d",*(student_ptr+j));
	}
	printf("\n");
	if(allover60)
		printf("best case\n");//allover60=1�A���Ƥή�
	else
		printf("%d\n",less_than60_max);//�L�X�̰����ή���� 
	if(not_allover60)
		printf("worst case\n");//not_allover60=1,�������ή�
	else
		 printf("%d\n",more_than60_min);
	free(student_ptr);//����ʺA�O���� 
	return 0;
 } 
 
 void swap(int *a,int *b)
 {
 	int temp=*a;
 	*a=*b;
 	*b=temp;
 	
 }
