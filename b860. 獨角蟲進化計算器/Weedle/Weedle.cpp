#include <iostream>
#include <cstdlib>
using namespace std;
/*�W���λݭn12���}�i�H�i�Ʀ��K�߸��A�A�i�Ʀ��j�w�W�n50���A�]�H�i�Ʀ��ƦҶq�A
���|�i�Ʀ��j�w�W�C���A���ثe�Ҿ֦����}�G�οW���μƶq�A
(���]���w�g��Ҧ����K�߸��Υѥ��A�i�ƦӦ����j�w�� (Beedrill)�ǰe���б¥H�����}�G�F�A
�ӥB�L�|�d�U�������W���ΥH���i��i��̦h���i��)�A�ЧA���L�p��@�U�L�{�b�i�H�����X���W���Ϊ��i�ơC*/
int main()
{
	int c, w,success=0;/*c:candy count  w:Weedle�ƶq*/
	cin >> c >> w;
	while (w >= 1)
	{
		if (c >= 12)
		{
			c = c-12+2;/*�i�ƥ�12��+�i�Ʀ��\1��+�ǰe�K�Ҹ�+��*/
			w -= 1;/*�i�ƥα��@���W����*/
			success++;
			continue;//�o���j��i�Ʀ��\�A���s�P�_�ण��A�i�ơA�����O����}�G�Υ��A�ǰe���i�ƪ�����
		}
		w -= 1; c += 1;/*�}�G�����A�ǰe�W����*/
	}
	
	cout << success;
	/*������:success=(c + w - 2) / 11
	���n�ݧڬ�����*/
}