#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int factorial(int n) {
	if (n > 0)
		return n * factorial(n - 1);
	else
		return 1;
}
int main() {
	int n;
	scanf("%d", &n);
	int num = 0;
	int i = 1;
	while (i <= n) {
		num = 1 * i;
	}
	printf("�ǵݹ���ã�%d\n", num);
	return 0;
}
int main44() {
	int n;
	scanf("%d", &n);
	printf("�ݹ���ã�%d\n", factorial(n));
	printf("�ǵݹ���ã�%d\n", factorial_(n));
	system("pause");
	return 0;
}