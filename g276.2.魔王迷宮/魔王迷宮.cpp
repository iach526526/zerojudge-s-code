#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
using namespace std;
int MAP[101][101] = { 0 };
int boss_life[500];
struct boss
{
	//��l�y��
	int now_x;
	int now_y;
	//�C�^�X���ʨB��
	int move_x;
	int move_y;
};
int  check(int k, int rangex, int rangey, boss* boss)
{


	if (boss_life[k])//�]���O����
	{
		if (boss->now_x > rangex || boss->now_y > rangey|| boss->now_x<0|| boss->now_y<0)//�ˬd�X��
		{
			boss_life[k] = 0;
			return 1;//�������]��
		}
		else
		{
			//�P�_�}�U���u
			if (MAP[boss->now_x][boss->now_y] == 1)//��쬵�u
			{
				boss_life[k] = 0;
				MAP[boss->now_x][boss->now_y] = 2;//���^�X�z����(�����h���]�����P�@�I�@�_�z�����ĪG)�A����Y���]�����]�|�z��
				return 1;//�������]��
			}
			else if (MAP[boss->now_x][boss->now_y] == 2)//����z�����I��
			{
				boss_life[k] = 0;
				return 1;//�������]��
			}
		}

	}
	return 0;//safe or�o���]���w�g���F�C�^��0�ϩI�s��if�����ߡA���Φ��]����
}
void move(int rangex, int rangey, int k, boss* boss)
{
	if (boss_life[k])//�]���O����
	{
		//����+�񬵼u(MAP�y����1)
		MAP[boss->now_x][boss->now_y] = 1;//�񬵼u
		boss->now_x += boss->move_x;
		boss->now_y += boss->move_y;
	}

}
int main()
{
	
	int n, m, k;
	/* n,m�M�w�a�Ϥj�p
		k:�]���ƶq
	*/
	//scanf_s("%d%d%d", &n, &m, &k);
	cin >> n >> m >> k;
	//�D�إ������nm*n�����e�A��X�Ӫ����G
	//��xor���ܼƥ洫
	m ^= n;
	n ^= m;
	m ^= n;
	for (int i = 0; i < k; i++)
	{
		boss_life[i] = 1;
	}
	boss blist[500];
	for (int kc = 0; kc < k; kc++)
	{

		for (int i = 0; i < 4; i++)
		{
			switch (i)//�����]���̪�l�ݩ�
			{
			case 0:
				//scanf_s("% d", &blist[kc].now_x);
				cin >> blist[kc].now_x;
				break;
			case 1:
				//scanf_s("% d", &blist[kc].now_y);
				cin >> blist[kc].now_y;
				break;
			case 2:
				//scanf_s("% d", &blist[kc].move_x);
				cin >> blist[kc].move_x;
				break;
			case 3:
				//scanf_s("% d", &blist[kc].move_y);
				cin >> blist[kc].move_y;
				break;
			default:
				break;
			}
		}
	}
	//�յۿ�X�]���ݩ� 
//	for (int kc = 0; kc < k; kc++)
//	{
//		cout<<kc<<":"<<blist[kc].now_x<<" "<<blist[kc].now_y<<" "<<blist[kc].move_x<<" "<<blist[kc].move_y<<endl;
//	}
	int boss_count = k, bomb_count = 0;
	//K:�]���ƶq 
	while (boss_count != 0) {
		//printf("|");
		bomb_count = 0;
		for (int kc = 0; kc < k; kc++)
		{
			move(m, n, kc, &blist[kc]);//�����]��
		}

		for (int kc = 0; kc < k; kc++)//���ʧ��ˬd
		{
			if (check(kc, m, n, &blist[kc]))
			{
				boss_count--;
			}
		}


		//����B��z�a�ϤW�����u 
		for (int index_m = 0; index_m < m; index_m++)
		{
			for (int index_n = 0; index_n < n; index_n++)//�Ƭ��u 
			{
				if (MAP[index_m][index_n] == 1)
				{
					bomb_count++;
				}
				else if (MAP[index_m][index_n] == 2)
				{
					MAP[index_m][index_n] = 0;//���z�������A�M��
				}
			}
		}

	}
	printf("%d", bomb_count);
	return 0;

}

