#include <iostream>
#include <cstdlib>
using namespace std;
//�Ĥ@�榳�@�ӥ����n(1 <= n <= 1000)�A�N���X�ӼƦr�n�ЧA������
//
//�ĤG�榳n�ӥi�H��int�x�s�������
int main()
{
	int n;
	while (cin >> n)
	{
		int number_arr[1000] = { '\0' };
		//��J�Ʀr
		for (int i = 0; i < n; i++)
		{
			cin >> number_arr[i];
		}
		//��w�Ƨ�
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