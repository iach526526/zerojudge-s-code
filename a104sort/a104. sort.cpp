#include <iostream>
#include <cstdlib>
using namespace std;
//第一行有一個正整數n(1 <= n <= 1000)，代表有幾個數字要請你幫忙排
//
//第二行有n個可以用int儲存的正整數
int main()
{
	int n;
	while (cin >> n)
	{
		int number_arr[1000] = { '\0' };
		//輸入數字
		for (int i = 0; i < n; i++)
		{
			cin >> number_arr[i];
		}
		//氣泡排序
		for(int i = n-1; i >= 0; i--)
		{
			for (int j = 0; j <i; j++)
			{
				if (number_arr[j] > number_arr[j + 1])
				{
					int temp;
					temp = number_arr[j];
					number_arr[j] = number_arr[j + 1];
					number_arr[j + 1] = temp;
				}
			}
		}
		for (int k = 0; k < n; k++)
		{
			cout << number_arr[k]<<' ';
		}
		cout << endl;
	}
}