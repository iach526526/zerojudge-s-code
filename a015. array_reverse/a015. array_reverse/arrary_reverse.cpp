#include <iostream>
#include <cstdlib>
using namespace std;
void print_arr(int array[][100],int row, int col)
{
	for (int count_row = 0; count_row < row; count_row++)
	{
		for (int count_col = 0; count_col < col; count_col++)
		{
			cout << array[count_row][count_col] << " ";
		}
		cout << endl;
	}
}
int main()
{
	int row,col;
	int array[10][10];//�D�سW�w�d��A�̤j100*100
	while(cin >> row >> col)
	{
		int count_row, count_col;//�ŧi�j���ܼ�
		for (count_row = 0; count_row < row; count_row++)
		{
			for (count_col = 0; count_col < col; count_col++)
			{
				cin >> array[count_row][count_col];
			}
		}
		//print_arr(array, row, col);//���`��X
		//½�ण�L�Oindex���]col�A�A�]row
		/*
		[0,0][0,1][0,2]
		[1,0][1,1][1,2]

		[0,0] [1,0]
		[0,1] [1,1]
		[0,2] [1,2]
		*/
		for (int count_col = 0; count_col < col; count_col++)
		{
			for (int count_row = 0; count_row < row; count_row++) {
				cout << array[count_row][count_col]<<" ";
					}
			cout << endl;
		}
		
	}
	
}