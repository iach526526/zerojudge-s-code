#include <stdio.h>
int main()
{
	int N;
	/*�C�մ���u���@�Ӿ�� N 
	(0<=N<=100)�A�N��ǥͦb ZeroJudge�t��
	�W�ѥX���D��*/ 
	while(scanf("%d",&N)!=EOF)
	{
		if(N>=0 && N<=10)//�����D�Ʀb 0~10 �̡A�C�D��6��
			printf("%d\n",6*N);
		else if(N>10 &&N<=20)//�D�Ʀb 11~20 �̡A�q��11�D�}�l�A�C�D��2���C(�e10�D�٬O�C�D��6��)
			printf("%d\n",60+2*(N-10));
		else if(N>20&&N<=40)//�D�Ʀb 21~40 �̡A�q��21�D�}�l�A�C�D��1���C
			printf("%d\n",80+(N-20));
		else if(N>40)//�D�Ʀb 40 �H�W�̡A�@��100���C
			printf("100\n");
		
	}
 } 
