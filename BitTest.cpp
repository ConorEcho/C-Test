#include <iostream>
#include <cassert>
#include <vector>
using namespace std;



void SwapSort(vector<char>& pArr,vector<int>& pPos)
{
	assert(pArr.size()>0);
	assert(pPos.size()>0);
	assert(pArr.size() == pPos.size());

	char tmp = pArr[0];
	size_t counts = 1;
	int index = 0;
	while (counts < pArr.size())        //ѭ����ֹ����
	{
		if (index != pPos[index])
		{
			pArr[index] = pArr[pPos[index]];
			index = pPos[index];
			counts++;
		}
		else
		{
			index++;
			counts++;
		}
	}
	//���һ�������Ҫ���в���
	if (index != pPos[index])
	{
		pArr[index] = tmp;
	}
}

void NewSwapSort(vector<char>&pArr, vector<int>& pPos)
{
	assert(pArr.size()>0);
	assert(pPos.size()>0);
	assert(pArr.size() == pPos.size());

	char tmp	= pArr[0];						 //�ڿ�
	int  tmpPos = 0;							 //�õ����ڵĿ�λ�õ��±�
	size_t counts = 1;
	int index = 0;

	while (counts < pArr.size())
	{
		while (index == pPos[index])
		{
			index++;
			counts++;
		}

		if (index == pArr.size())
			break;

		//��index���ڿ�
		tmp = pArr[index];
		tmpPos = index;

		while (1)
		{
			//��ɽ���������
			if (index != pPos[index])
			{
				if (tmpPos == pPos[index])
				{
					//�����ǰpPos�е��±��뵱ǰ�ӵ��±���ͬ
					//�ѿӵ�Ԫ������pArr��
					pArr[index] = tmp;
					pPos[index] = index;

					index++;
					break;
				}
				//�����ǰpPos�е��±��뵱ǰ�ӵ��±겻ͬ
				//�򽻻�pArr��pPos[index]�е�Ԫ�ظ���ǰλ��
				pArr[index] = pArr[pPos[index]];

				//����pPos�еĶ�Ӧ�±�͵�ǰ�±�
				int j = pPos[index];
				pPos[index] = index;
				index = j;
				counts++;
			}
		}
	}
}

int main()
{
	char pArr[] = { 'A', 'B', 'C', 'D', 'E' };
	int pPos[] = { 2, 0, 1, 4, 3 };
	vector<char> v1(pArr, pArr + sizeof(pArr) / sizeof(pArr[0]));
	vector<int> v2(pPos, pPos + sizeof(pPos) / sizeof(pPos[0]));
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	NewSwapSort(v1, v2);
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	return 0;
}