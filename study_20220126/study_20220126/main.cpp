#include<stdio.h>
#include<vector>
using namespace std;


void bubble_sort(vector<int>& ivec);
void select_sort(vector<int>& ivec);
void insert_sort(vector<int>& ivec);
void quick_sort(vector<int>& ivec);

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}


void bubble_sort(vector<int>& ivec)
{
	for (auto i = 0; i < ivec.size() - 1; i++)
	{
		for (auto j = 0; j < ivec.size() - i - 1; j++)
		{
			if (ivec[j] > ivec[j + 1])
			{
				swap(ivec[j], ivec[j + 1]);
			}
		}
	}
}

void select_sort(vector<int>& ivec)
{
	for (auto i = 0; i < ivec.size() - 1; i++)
	{
		for (auto j = i + 1; j < ivec.size(); j++)
		{
			if (ivec[i] > ivec[j])
			{
				swap(ivec[i], ivec[j]);
			}
		}
	}
}

void select_sort2(vector<int>& ivec)
{
	for (auto i = 0; i < ivec.size() - 1; i++)
	{
		int idx = i;
		for (auto j = i + 1; j < ivec.size(); j++)
		{
			if (ivec[idx] > ivec[j])
			{
				idx = j;
			}
		}
		swap(ivec[i], ivec[idx]);
	}
}

void insert_sort(vector<int>& ivec)
{
	for (auto i = 1; i < ivec.size(); i++)
	{
		int temp = ivec[i];
		int j = i - 1;

		while (j >= 0 && temp < ivec[j])
		{
			ivec[j + 1] = ivec[j];
			j--;
		}
		ivec[j + 1] = temp;
	}
}


//思想这两个问题：1. 是否可以先从左边开始找？ 2.交换的条件 能否不包含等于的情况
int partition(vector<int>& ivec, int left, int right)
{
	auto val = ivec[left];
	while (left<right)
	{
		//从右边开始遍历 把小于样本数的元素 放到左边
		while (val <= ivec[right] && left < right)
		{
			right--;
		}
		ivec[left] = ivec[right];

		//右边产生空位后，再从左边开始找 大于样本数的元素 放到右边
		while (val >= ivec[left] && left < right)
		{
			left++;
		}
		ivec[right] = ivec[left];
	}
	//左右指针重合时，将样本放在此位置
	ivec[left] = val;
	return left;
}

void quick_sort(vector<int>& ivec, int left, int right)
{
	if (left < right)
	{
		int mid = partition(ivec, left, right);
		quick_sort(ivec, left, mid - 1);
		quick_sort(ivec, mid + 1, right);
	}
}


void hanoi(int n, char a, char b, char c)
{
	if (n > 0)
	{
		hanoi(n - 1, a, c, b);
		printf("moving %d from %c to %c\n", n, a, c);
		hanoi(n - 1, b, a, c);
	}
}


//堆排序，调整堆----让堆成为大根堆
void sift(vector<int>& ivec, int low, int high)
{
	int temp = ivec[low];
	//i 指向堆顶， j指向左孩子
	auto i = low;
	auto j = 2 * i + 1;

	while (j <= high)
	{
		//找到左右儿子中较大的 然后和父节点比较
		if (j + 1 <= high && ivec[j + 1] > ivec[j])
		{
			j = j + 1;
		}
		if (ivec[j] > temp)
		{
			ivec[i] = ivec[j];
			i = j;
			j = 2 * i + 1;
		}
		else
		{
			ivec[i] = temp;
			break;
		}
	}
	//j到了high位置还是没找到
	ivec[i] = temp;
}

void heap_sort(vector<int> &ivec)
{
	//从最小的那个堆开始，调整，先找到倒数一个小堆的根，然后直到最后一个元素
	auto len = ivec.size();

	//请注意  int i  不能用  auto i，否则会出现莫名的错误，表现为 for循环停不下来
	for (int i = (len - 2) / 2; i >= 0; i--)
	{
		//printf("%d\n", i);
		sift(ivec, i, len - 1);
	}
	//把最大的依次往数组后面倒着放进去
	for (int i = ivec.size() - 1; i > 0; i--)
	{
		swap(ivec[0], ivec[i]);
		sift(ivec, 0, i - 1);
	}
}

int main()
{
	//vector<int> a = { 2,1,34,102,465,12,55,10,31 };
	vector<int> a = { 20,1,34,102,465,12,55,10,31 };
	vector<int> b = { 2,8,3,9,5,7,6 };
	//bubble_sort(a);
	//select_sort2(a);
	//insert_sort(a);
	//quick_sort(a, 0, a.size() - 1);
	//hanoi(3, 'A', 'B', 'C');
	//sift(b, 0, b.size() - 1);
	heap_sort(a);
	return 0;
}