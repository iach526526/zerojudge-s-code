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
	int array[10][10];//題目規定範圍，最大100*100
	while(cin >> row >> col)
	{
		int count_row, count_col;//宣告迴圈變數
		for (count_row = 0; count_row < row; count_row++)
		{
			for (count_col = 0; count_col < col; count_col++)
			{
				cin >> array[count_row][count_col];
			}
		}
		//print_arr(array, row, col);//正常輸出
		//翻轉不過是index先跑col，再跑row
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