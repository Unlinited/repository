#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
unsigned int reverse_bit(unsigned  n) {
	unsigned int temp ,sum = 0;
	for (int i=0; i < 32; i++, n /= 2) {
		temp = n % 2;
		sum = sum * 2 + temp;
	}
	return sum;
}
int main() {
	unsigned a = 0;
	printf("������һ�����֣�\n");
	scanf("%d", &a);
	printf("��ת��Ϊ:%u\n", reverse_bit(a));
	system("pause");
	return 0;
}