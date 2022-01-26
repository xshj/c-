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


//˼�����������⣺1. �Ƿ�����ȴ���߿�ʼ�ң� 2.���������� �ܷ񲻰������ڵ����
int partition(vector<int>& ivec, int left, int right)
{
	auto val = ivec[left];
	while (left<right)
	{
		//���ұ߿�ʼ���� ��С����������Ԫ�� �ŵ����
		while (val <= ivec[right] && left < right)
		{
			right--;
		}
		ivec[left] = ivec[right];

		//�ұ߲�����λ���ٴ���߿�ʼ�� ������������Ԫ�� �ŵ��ұ�
		while (val >= ivec[left] && left < right)
		{
			left++;
		}
		ivec[right] = ivec[left];
	}
	//����ָ���غ�ʱ�����������ڴ�λ��
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


//�����򣬵�����----�öѳ�Ϊ�����
void sift(vector<int>& ivec, int low, int high)
{
	int temp = ivec[low];
	//i ָ��Ѷ��� jָ������
	auto i = low;
	auto j = 2 * i + 1;

	while (j <= high)
	{
		//�ҵ����Ҷ����нϴ�� Ȼ��͸��ڵ�Ƚ�
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
	//j����highλ�û���û�ҵ�
	ivec[i] = temp;
}

void heap_sort(vector<int> &ivec)
{
	//����С���Ǹ��ѿ�ʼ�����������ҵ�����һ��С�ѵĸ���Ȼ��ֱ�����һ��Ԫ��
	auto len = ivec.size();

	//��ע��  int i  ������  auto i����������Ī���Ĵ��󣬱���Ϊ forѭ��ͣ������
	for (int i = (len - 2) / 2; i >= 0; i--)
	{
		//printf("%d\n", i);
		sift(ivec, i, len - 1);
	}
	//������������������浹�ŷŽ�ȥ
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