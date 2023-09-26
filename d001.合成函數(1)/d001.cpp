//https://judge.tcirc.tw/ShowProblem?problemid=d001
#include <cstdlib>
#include <iostream>
#include <math.h> 
using namespace std;
char* chptr;
int FC()
{
	while (*chptr == ' '|| *chptr == '\n')
	{
		// ���L�Ů�
		++chptr;
	}
	if (*chptr == 'f')
	{
		int x; ++chptr;
		x = FC();
		return 2 * x - 1;
	}
	else if (*chptr == 'g')
	{
		int x, y; ++chptr;
		x = FC(); ++chptr;
		y = FC();
		return x + 2 * y - 3;
	}
	else if(*chptr == '-')//�t��
	{
		int num = 0; 
		++chptr;//�}�lŪ���ӭt��
		while (*chptr >= '0' && *chptr <= '9')
		{
			num = num * 10 + (*chptr - '0');
			++chptr;
		}
		return 0-num;
	}
	else//�����
	{
		int num = 0;
		while (*chptr >= '0' && *chptr <= '9')
		{
			num = num * 10 + (*chptr - '0');
			++chptr;
		}
		return num;
	}
	
}

int main()
{
	//char in_char[10000] = { 'f','g','f','1','3' };//��ʴ���
	char in_char[1000]={0} ;
	int i = 0; char c;
	while (cin.get(c) && c != '\n')
	{
		in_char[i++] = c;
	}

	//�}�C��X����
//	for(int j=0;j<i;j++)
//	{
//		cout<<in_char[j];
//	}
	chptr = &in_char[0];
	long long ans = FC();
	cout << ans;
}
