/*1��дһ���������ӿڣ�����ɶ�������С��������
2���ӿ��жഫ��һ��ȱʡ�����������ָ�����Ͳ���A����ʽ�����ָ���ˣ��Ͱ�����ѡ���������ʽ�����ٰ������֣���
3���������Ļ����ϣ���ɶԽṹ�������ͨ�������жϴ�С�ĺ�����ʵ�֡�
*/

#include<iostream>
#include<stdlib.h>
using namespace std;

void Sort(int*src1,int n)
{

	int i, j,k;
	int tmp;
	for (i = 1; i < n; i++)//������ڶ������ݿ�ʼ�Ƚϣ����±�Ϊ1������
	{
		tmp = src1[i];//�Ȱ�Ҫ���Ƚϵ����ݱ���
		for (j = i; j >= 0 && src1[j - 1] > tmp; j--)//j��ʾ����i֮ǰ�������±꣬��j>=0,��Ԫ�ش����±�Ϊi�����ݣ���������ѭ��
		{
			src1[j] = src1[j - 1];//���ƴ���tmp������
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
	for (i = 1; i < n; i++)//������ڶ������ݿ�ʼ�Ƚϣ����±�Ϊ1������
	{
		tmp = src[i];//�Ȱ�Ҫ���Ƚϵ����ݱ���
		for (j = i; j >= 0 && src[j - 1] > tmp; j--)//j��ʾ����i֮ǰ�������±꣬��j>=0,��Ԫ�ش����±�Ϊi�����ݣ���������ѭ��
		{
			src[j] = src[j - 1];//���ƴ���tmp������
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
	cout << "�Ƿ�ѡ������ʽ,���ǣ�����1,�����ǣ�����0��Ĭ��ѡ��ð������\n";
	cin >> n;
	if(n == 1)
	{
		cout << "ѡ������ʽ:\n1.��������\n2.С������\n3.ð������\n";
		cin >> k;
		Sort2(src1, src, 10, 10, k);
	}
	else
	{
		Sort2(src1, src, 10, 10);
	}
	
	system("pause");
}