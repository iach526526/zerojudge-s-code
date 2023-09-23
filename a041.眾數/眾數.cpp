?#include <iostream>
#include <cstdlib>
using namespace std;
void quickSort(int arr[], int left, int right)
{
	/*int temp;*/
	if (left < right)
	{
		int pivot = arr[left];//假設pivot在第一個的位置
		int l = left;
		int r = right + 1;

		while (1)
		{
			while (l < right && arr[++l] < pivot);//向右找小於pivot的數值的位置
			while (r > 0 && arr[--r] > pivot);//向左找大於pivot的數值的位置

			if (l >= r)//範圍內pivot右邊沒有比pivot小的數,反之亦然
			{
				break;
			}

			swap(arr[l], arr[r]);//比pivot大的數移到右邊，比pivot小的數換到左邊
		}

		swap(arr[left], arr[r]);//將pivot移到中間

		quickSort(arr, left, r - 1);//左子數列做遞迴
		quickSort(arr, r + 1, right);//右子數列做遞迴
	}

}

void swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
struct mode//眾數
{
	int how_many;
	int value;
};
void processing(int*,int);
int main() {

	int* in_arr = NULL;
	in_arr = (int*)malloc(1 * sizeof(int));//先配置一個整數空間當初始，後面要用再加
	int max_index = 0;
	int this_num;
	while (cin >> this_num) {
		in_arr =(int *) realloc(in_arr, (max_index +1)* sizeof(int));//多添加一個空間在原始陣列後方
		in_arr[max_index] = this_num;
		char c;
		c = getchar();
		if (c != ' ')
		{
			processing(in_arr, max_index);
			max_index = 0;//初始化，跑下一筆測資
			in_arr = NULL;
			continue;
		}
			
		max_index++;
	}

}

void processing(int* in_arr,int max_index)
{
	//若要遍歷，max_index從0開始，若有n個數字數入(首項叫第一個數字)，則max_index=n-1
	quickSort(in_arr, 0, max_index);
	//輸出測試
	/*for (int j = 0; j <= max_index; j++)
	{
		if (j == 0)
		{
			cout << in_arr[j];
			continue;
		}

		cout << " " << in_arr[j];
	}
	cout << endl;*/
	//輸出測試
	int* now_index = in_arr;//遍歷指標*now_index在指向in_arr的起始

	struct mode this_mode; this_mode.how_many = 0; this_mode.value = *now_index;
	int have_been_ran = 0;//標註外層while是不是第一次跑
	int j = 1;//j:這次判斷的數組出現次數
	for (int i = 0; i < max_index; i++)//末項不用和下一項比較，i跑到max_index-1就好
	{
		while (*(now_index + j - 1) == *(now_index + j))//從自己現在這項和後面一項比較有沒有相同，若有則J++
		{
			j++;
		}
		if (j > this_mode.how_many)
		{
			this_mode.how_many = j;//更新
			this_mode.value = *(now_index);
		}
		now_index = (now_index + j);//把遍歷指標指向下一組不同的數字開頭
		i = i + j;
		j = 1;
	}
	/*cout << endl << "value:" << this_mode.value;
	cout << endl << "turn:" << this_mode.how_many;*/

	//this_mode.how_many和this_mode.value分別儲存出現次數最多的數字和值了
	//再來判斷眾數出現多組次數一樣的狀況(都要輸出)
	now_index = in_arr;//遍歷指標*now_index指向in_arr的起始
	bool find_friend = false;//有沒有出現多組眾數憑據
	for (int count_index = 0; count_index <= max_index;)//讓迴圈結尾那邊加
	{
		int same = 1;
		while (now_index[same - 1] == now_index[same])
		{
			same++;
		}
		if (same == this_mode.how_many)//又找到一個與出現次數最多的數字一樣的次數
		{

			if (!find_friend)//前面若沒有輸出過，第一個不用空白
			{
				cout << now_index[0];
			}
			else
			{
				cout << " " << now_index[0];
			}
			find_friend = true;
		}
		//把跳過的index加上
		now_index = now_index + same;
		count_index += same;
	}
	if (!find_friend)
	{
		cout << this_mode.value;
	}
	cout << endl;
	free(in_arr);//歸還動態空間
}
