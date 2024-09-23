#define	_CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}
//时间复杂度O(n^2)
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}
//时间复杂度O(logn*n)/O(log3n*n)
//平均O(N^1.3)
void ShellSort(int* a,int n)
{

	int gap = 0;
	while (gap > 1)
	{
		gap /= 2;
		for (int i = 0; i < n - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
	
}

void Swap(int* dst, int* src)
{
	int tmp = *dst;
	*dst = *src;
	*src = tmp;
}

void  SelectSort(int* a, int n)
{
	//int left = 0, right = n - 1;
	//while (left < right)
	//{
	//	int min = left, max = right;
	//	for (int i = left; i <= right; i++)
	//	{
	//		if (a[i] < a[min])
	//		{
	//			min = i;
	//		}
	//		if (a[i] > a[max])
	//		{
	//			max = i;
	//		}
	//	}
	//	Swap(&a[left], &a[min]);
	//	Swap(&a[right], &a[max]);
	//	left++;
	//	right--;
	//}
	for (int i = 0; i < n; i++)
	{
		int minIndex = i;
		int j = i + 1;
		for (j; j < n; j++)
		{
			if (a[j] < a[minIndex])
			{
				minIndex = j;
			}
		}
		Swap(&a[i], &a[minIndex]);
	}
}

void AdjustDown(int* a, int n, int root)
{

}
//N*logN
void HeapSort(int* a,int n)
{
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}

}

void BubbleSort(int* a, int n)
{
	int right = n - 1;
	while(right>0)
	{
		int flag = 0;
		for (int i = 0; i < right; i++)
		{
			if (a[i] > a[i + 1])
				Swap(&a[i], &a[i + 1]);
			flag = 1;
		}
		if (flag == 0)
			break;
		right--;
	}
}

int GetMinIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;
	if (a[left] > a[mid] && a[left] > a[right])
	{
		if (a[mid] > a[right])
			return mid;
		else
			return right;
	}
	else if (a[left] < a[mid] && a[left] < a[right])
	{
		if (a[mid] > a[right])
			return right;
		else
			return mid;
	}
	else
		return left;
}
//挖坑法
int PartSort1(int* a, int left, int right)
{
	int midIndex = GetMinIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);
	int begin = left;
	int end = right;
	int pivot = begin;
	int key = a[left];
	while (begin < end)
	{
		while (begin < end && a[end] >= key)//必须>=，不然死循环
			end--;
		a[pivot] = a[end];
		pivot = end;
		while (begin < end && a[begin] <= key)
			begin++;
		a[pivot] = a[begin];
		pivot = begin;
	}
	a[pivot] = key;
	return pivot;
}

int PartSort2(int* a, int left, int right)
{
	int midIndex = GetMinIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);
	int begin = left;
	int end = right;
	int keyi = left;
	while (begin < end)
	{
		while (begin < end && a[begin] <= a[keyi])//必须>=，不然死循环
		{
			begin++;
		}
		while (begin < end && a[end] >= a[keyi])
		{
			end--;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[left], &a[begin]);
	return begin;
}
int PartSort3(int* a, int left, int right)
{
	int midIndex = GetMinIndex(a, left, right);
	Swap(&a[left], &a[midIndex]);
	int cur = left+1;
	int prev = left;
	int keyi = left;
	while (cur <= right)
	{
		if (a[cur] < a[keyi] && ++prev != cur)
			Swap(&a[prev], &a[cur]);
		cur++;
	}
	Swap(&a[keyi], &a[prev]);
	return prev;
}

//nlogn
void QuickSort(int* a, int left,int right)
{
	if (left >= right)
		return;
	int keyIndex = PartSort3(a, left, right);//单趟排序
	//小区间优化
	if (keyIndex - left > 10)
		QuickSort(a, left, keyIndex - 1);
	else
		InsertSort(a + left, keyIndex - 1 - left + 1);
	if (right - (keyIndex + 1) > 10)
		QuickSort(a, keyIndex + 1, right);
	else
		InsertSort(a + keyIndex + 1, right - (keyIndex + 1) + 1);
}

void _MergeSort(int* a, int left, int right,int* tmp)
{
	if (left >= right)
		return;
	int mid = (left + right) >> 1;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	while(begin1 <= end1)
	{
		tmp[index++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[index++] = a[begin2++];
	}
	//memcpy(a + left, tmp + left, sizeof(int) * (index - left));
	for (int i = left; i <= right; i++)
	{
		a[i] = tmp[i];
	}
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1,tmp);
	free(tmp);
}

void TestMergeSort()
{
	int a[] = { 3,2,5,7,8,6,1,9,4,0 };
	MergeSort(a,sizeof(a) / sizeof(a[0]));
	PrintArray(a, sizeof(a) / sizeof(a[0]));
}
int main()
{
	//TestMergeSort();
	int prev = 1;
	int cur = 1;
	int next = 0;
	for (int i = 3; i <= 50; i++)
	{
		next = prev + cur;//2 3
		prev = cur;//1 2
		cur = next;//2 3
	}
	printf("%d ", next);
	return 0;
}

