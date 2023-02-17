#include <stdio.h>
#include <stdlib.h>
void swap(int *,int *);
int main()
{
	int how_many;
	scanf("%d",&how_many);//學生數量 
	int *student_ptr=(int *)malloc(sizeof(int)*how_many);//student_ptr學生成績 
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
	for(j=0;j<=count;j++)//把排序過的資料讀一次輸出(第一行)並找出最高不及格分數，如果全數及格時，allover60=1； 
	{
		if(*(student_ptr+j)<60)
		{
			less_than60_max=*(student_ptr+j);//已經排序，每次還有符合條件可以直接取代
			allover60=0;//沒有全數及格的標記 
		}
		else
		{
			if(more_than60_min<*(student_ptr+j))
			{
				if(not_allover60!=0)
					more_than60_min=*(student_ptr+j);//表示這是第一個讀到(及最低)的及格成績 
				not_allover60=0;//沒有全不及格的標記 
			}
		}
		if(j==0)
			printf("%d",*(student_ptr+j));
		else
			printf(" %d",*(student_ptr+j));
	}
	printf("\n");
	if(allover60)
		printf("best case\n");//allover60=1，全數及格
	else
		printf("%d\n",less_than60_max);//印出最高不及格分數 
	if(not_allover60)
		printf("worst case\n");//not_allover60=1,全都不及格
	else
		 printf("%d\n",more_than60_min);
	free(student_ptr);//釋放動態記憶體 
	return 0;
 } 
 
 void swap(int *a,int *b)
 {
 	int temp=*a;
 	*a=*b;
 	*b=temp;
 	
 }
