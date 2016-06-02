#ifndef __GETKLEASTNUM_H__
#define __GETKLEASTNUM_H__
#include <iostream>
using namespace std;
#include "assert.h"

int* GetKLeastNum(int* a,size_t k,size_t totleNum)
{
	//创建一个数组用来保存K个数据
	int* ret = new int[k];
	//先往数组中放入K个数
	for (int i = 0; i < k; i++)
	{
		ret[i] = a[i];
	}

	//建堆
	for (int i = (k - 2) / 2; i >= 0; i--)
	{
		AdjustDown(ret, k, i);
	}

	for (int i = k; i < totleNum; i++)
	{
		//如果拿到的数比堆头小，那么交换值，然后调整
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
		//找出孩子中的最大值
		if (child + 1 < size && a[child] < a[child + 1])
		{
			++child;
		}
		//拿父节点与最大子节点做比较
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