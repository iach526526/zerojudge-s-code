//https://zerojudge.tw/ShowProblem?problemid=a005 
#include <iostream>
#include <cstdlib>
using namespace std;
void output_arr(int*);
int main()
{
	int t;//測資數量
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		int digit_string[4] = {0};//每行均包含四個整數，表示數列的前四項
		for (int count = 0; count <= 3; count++)
		{
			cin >> digit_string[count];//輸入前4項
		}
		if (digit_string[0] + digit_string[2] == digit_string[1]*2)//用等差中項的概念判斷是否為等差數列
		{
			int d = digit_string[1] - digit_string[0];//計算公差
			output_arr(&digit_string[0]);//輸出剛剛輸入的+第五項
			cout << digit_string[3] +d<<endl;
		}
		else {//那就是等比囉
			int r = digit_string[1] / digit_string[0];
			output_arr(&digit_string[0]);//輸出剛剛輸入的+第五項
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
