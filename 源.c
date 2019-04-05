#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int func(int n) {
	if (n < 3)
		return 1;
	else
		return func(n - 1) + func(n - 2);
}
int main() {
	int  n;
	scanf("%d", &n);
	int func(int n);
	printf("%d\n", func( n));
	system("pause");
	return 0;

}
