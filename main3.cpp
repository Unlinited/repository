/*1、写一个排序函数接口，能完成对整数和小数的排序。
2、接口中多传入一个缺省参数，如果不指定，就采用A排序方式，如果指定了，就按他的选择决定排序方式（至少包含三种）。
3、在上述的基础上，完成对结构体的排序。通过传入判断大小的函数来实现。
*/

#include<iostream>
#include<stdlib.h>
using namespace std;

void Sort(int*src1,int n)
{

	int i, j,k;
	int tmp;
	for (i = 1; i < n; i++)//从数组第二个数据开始比较，即下标为1的数据
	{
		tmp = src1[i];//先把要被比较的数据备份
		for (j = i; j >= 0 && src1[j - 1] > tmp; j--)//j表示的是i之前的数据下标，若j>=0,且元素大于下标为i的数据，进行以下循环
		{
			src1[j] = src1[j - 1];//后移大于tmp的数据
		}
		src1[j] = tmp;
	}
	for (k = 0; k < n; k++)
	{
		cout << ("%d", src1[k])<<" ";
	}
	cout << "\n";
}
void Sort(double*src, int n)
{

	int i, j,k;
	double tmp;
	for (i = 1; i < n; i++)//从数组第二个数据开始比较，即下标为1的数据
	{
		tmp = src[i];//先把要被比较的数据备份
		for (j = i; j >= 0 && src[j - 1] > tmp; j--)//j表示的是i之前的数据下标，若j>=0,且元素大于下标为i的数据，进行以下循环
		{
			src[j] = src[j - 1];//后移大于tmp的数据
		}
		src[j] = tmp;
	}
	for (k = 0; k < n; k++)
	{
		cout << ("%d  ", src[k])<<"    ";
	}
	cout << "\n";
}


void MSort(int* src, int n)
{
	int i, j,tmp,k = 0;
	for (j = 0; j < n-1; j++) 
	{
		for (i = 0; i < n-1-j; i++)
		{
			if (src[i] > src[i + 1])
			{
				tmp = src[i];
				src[i] = src[j];
				src[j] = tmp;
			}
		}
	}
	for (k = 0; k < n; k++)
	{
		cout << ("%d  ", src[k]) << "    ";
	}
	cout << "\n";
}
void Sort1(int*src1, double* src, int a, int b)
{
	Sort(src1, a);
	cout << "\n";
	Sort(src, b);
	
}
void Sort2(int*src1,double* src ,int a,int b,int k=0)
{
	if (k == 1)
	{
		Sort(src1, a);
	}
	if (k == 2)
	{
		Sort(src, b);
	}
	if (k == 3)
	{
		MSort(src1, 10);
	}
	if (k == 0)
	{
		MSort(src1, 10);
	}
}

int main()
{
	int src1[10] = { 4,3,5,7,1,8,2,9,10,0 };
	double src[10] = { 3.0,7.0,5.6,6.8,9.3,2.6,1.6,8.9,1.9,8.1 };
	int k,n ;
	Sort1(src1, src, 10, 10);
	cout << "\n";
	cout << "是否选择排序方式,若是，输入1,若不是，输入0则默认选择冒泡排序\n";
	cin >> n;
	if(n == 1)
	{
		cout << "选择排序方式:\n1.整数排序\n2.小数排序\n3.冒泡排序\n";
		cin >> k;
		Sort2(src1, src, 10, 10, k);
	}
	else
	{
		Sort2(src1, src, 10, 10);
	}
	
	system("pause");
}