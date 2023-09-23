#include <stdio.h>
int main()
{
	int N;
	/*每組測資只有一個整數 N 
	(0<=N<=100)，代表學生在 ZeroJudge系統
	上解出的題數*/ 
	while(scanf("%d",&N)!=EOF)
	{
		if(N>=0 && N<=10)//答對題數在 0~10 者，每題給6分
			printf("%d\n",6*N);
		else if(N>10 &&N<=20)//題數在 11~20 者，從第11題開始，每題給2分。(前10題還是每題給6分)
			printf("%d\n",60+2*(N-10));
		else if(N>20&&N<=40)//題數在 21~40 者，從第21題開始，每題給1分。
			printf("%d\n",80+(N-20));
		else if(N>40)//題數在 40 以上者，一律100分。
			printf("100\n");
		
	}
 } 
