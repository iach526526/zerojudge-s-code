//https://zerojudge.tw/ShowProblem?problemid=a005 
#include <iostream>
#include <cstdlib>
using namespace std;
void output_arr(int*);
int main()
{
	int t;//����ƶq
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int digit_string[4] = {0};//�C�槡�]�t�|�Ӿ�ơA��ܼƦC���e�|��
		for (int count = 0; count <= 3; count++)
		{
			cin >> digit_string[count];//��J�e4��
		}
		if (digit_string[0] + digit_string[2] == digit_string[1]*2)//�ε��t�����������P�_�O�_�����t�ƦC
		{
			int d = digit_string[1] - digit_string[0];//�p�⤽�t
			output_arr(&digit_string[0]);//��X����J��+�Ĥ���
			cout << digit_string[3] +d<<endl;
		}
		else {//���N�O�����o
			int r = digit_string[1] / digit_string[0];
			output_arr(&digit_string[0]);//��X����J��+�Ĥ���
			cout << digit_string[3] * r<<endl;
		}
		
	}
}
void output_arr(int *a)
{
	for (int count = 0; count <= 3; count++)
	{
		cout<<*(a+count) << " ";
	}
}
