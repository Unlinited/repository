#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Stdlib.h>
int func(int n) {
	int c = 0;
	int f1 = 1;
	int f2 = 1;
	if (n < 3) {
		return 1;
	}
	else {
		for (int i = 3; i <= n; i++) {
			c = f1 + f2;
			f1 = f2;
			f2 = c;
		}
		return c;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	int func(n);
	printf("%d\n", func( n));
	system("pause");
	return 0;
}