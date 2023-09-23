?#include <iostream>
#include <cstdlib>
using namespace std;
void quickSort(int arr[], int left, int right)
{
	/*int temp;*/
	if (left < right)
	{
		int pivot = arr[left];//���]pivot�b�Ĥ@�Ӫ���m
		int l = left;
		int r = right + 1;

		while (1)
		{
			while (l < right && arr[++l] < pivot);//�V�k��p��pivot���ƭȪ���m
			while (r > 0 && arr[--r] > pivot);//�V����j��pivot���ƭȪ���m

			if (l >= r)//�d��pivot�k��S����pivot�p����,�Ϥ���M
			{
				break;
			}

			swap(arr[l], arr[r]);//��pivot�j���Ʋ���k��A��pivot�p���ƴ��쥪��
		}

		swap(arr[left], arr[r]);//�Npivot���줤��

		quickSort(arr, left, r - 1);//���l�ƦC�����j
		quickSort(arr, r + 1, right);//�k�l�ƦC�����j
	}

}

void swap(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
struct mode//����
{
	int how_many;
	int value;
};
void processing(int*,int);
int main() {

	int* in_arr = NULL;
	in_arr = (int*)malloc(1 * sizeof(int));//���t�m�@�Ӿ�ƪŶ����l�A�᭱�n�ΦA�[
	int max_index = 0;
	int this_num;
	while (cin >> this_num) {
		in_arr =(int *) realloc(in_arr, (max_index +1)* sizeof(int));//�h�K�[�@�ӪŶ��b��l�}�C���
		in_arr[max_index] = this_num;
		char c;
		c = getchar();
		if (c != ' ')
		{
			processing(in_arr, max_index);
			max_index = 0;//��l�ơA�]�U�@������
			in_arr = NULL;
			continue;
		}
			
		max_index++;
	}

}

void processing(int* in_arr,int max_index)
{
	//�Y�n�M���Amax_index�q0�}�l�A�Y��n�ӼƦr�ƤJ(�����s�Ĥ@�ӼƦr)�A�hmax_index=n-1
	quickSort(in_arr, 0, max_index);
	//��X����
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
	//��X����
	int* now_index = in_arr;//�M������*now_index�b���Vin_arr���_�l

	struct mode this_mode; this_mode.how_many = 0; this_mode.value = *now_index;
	int have_been_ran = 0;//�е��~�hwhile�O���O�Ĥ@���]
	int j = 1;//j:�o���P�_���ƲեX�{����
	for (int i = 0; i < max_index; i++)//�������ΩM�U�@������Ai�]��max_index-1�N�n
	{
		while (*(now_index + j - 1) == *(now_index + j))//�q�ۤv�{�b�o���M�᭱�@��������S���ۦP�A�Y���hJ++
		{
			j++;
		}
		if (j > this_mode.how_many)
		{
			this_mode.how_many = j;//��s
			this_mode.value = *(now_index);
		}
		now_index = (now_index + j);//��M�����Ы��V�U�@�դ��P���Ʀr�}�Y
		i = i + j;
		j = 1;
	}
	/*cout << endl << "value:" << this_mode.value;
	cout << endl << "turn:" << this_mode.how_many;*/

	//this_mode.how_many�Mthis_mode.value���O�x�s�X�{���Ƴ̦h���Ʀr�M�ȤF
	//�A�ӧP�_���ƥX�{�h�զ��Ƥ@�˪����p(���n��X)
	now_index = in_arr;//�M������*now_index���Vin_arr���_�l
	bool find_friend = false;//���S���X�{�h�ղ��ƾ̾�
	for (int count_index = 0; count_index <= max_index;)//���j�鵲������[
	{
		int same = 1;
		while (now_index[same - 1] == now_index[same])
		{
			same++;
		}
		if (same == this_mode.how_many)//�S���@�ӻP�X�{���Ƴ̦h���Ʀr�@�˪�����
		{

			if (!find_friend)//�e���Y�S����X�L�A�Ĥ@�Ӥ��Ϊť�
			{
				cout << now_index[0];
			}
			else
			{
				cout << " " << now_index[0];
			}
			find_friend = true;
		}
		//����L��index�[�W
		now_index = now_index + same;
		count_index += same;
	}
	if (!find_friend)
	{
		cout << this_mode.value;
	}
	cout << endl;
	free(in_arr);//�k�ٰʺA�Ŷ�
}
