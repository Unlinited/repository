#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩
int Find_Num(int a[],int y) {
	int num = 0;
	for (int i = 0; i < y; i++) {
		num ^= a[i];  //������ͬ���������Ϊ0
	}
	return num;
}
int main() {
	int a[9] = { 1,1,2,3,3,4,4,5,5 };
	printf("%d\n", Find_Num(a, 9));   //����Ĵ���
	system("pause");
	return 0;

}