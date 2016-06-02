#ifndef __GETKLEASTNUM_H__
#define __GETKLEASTNUM_H__
#include <iostream>
using namespace std;
#include "assert.h"

int* GetKLeastNum(int* a,size_t k,size_t totleNum)
{
	//����һ��������������K������
	int* ret = new int[k];
	//���������з���K����
	for (int i = 0; i < k; i++)
	{
		ret[i] = a[i];
	}

	//����
	for (int i = (k - 2) / 2; i >= 0; i--)
	{
		AdjustDown(ret, k, i);
	}

	for (int i = k; i < totleNum; i++)
	{
		//����õ������ȶ�ͷС����ô����ֵ��Ȼ�����
		if (ret[0] > a[i])
		{
			swap[ret[0],a[i]];
			AdjustDown(ret, k, 0);
		}
	}

	return ret;
}

void AdjustDown(int* a, size_t size, int i)
{
	assert(a);
	int parent = i;
	int child = 2 * parent + 1;
	while (child < size)
	{
		//�ҳ������е����ֵ
		if (child + 1 < size && a[child] < a[child + 1])
		{
			++child;
		}
		//�ø��ڵ�������ӽڵ����Ƚ�
		if (a[parent] < a[child])
		{
			swap(a[parent], a[child]);
			parent = child;
			child = 2 * parent + 1;
		}

		else
		{
			break;
		}
	}
}



#endif //__GETKLEASTNUM_H__