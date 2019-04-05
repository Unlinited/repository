#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
DigitSum(n) {
	int num = 0;
	int k;
	if (n != 0) {
	    k = n % 10;
		num= k + DigitSum(n/10);
	}
	return num;
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n",DigitSum (n));
	system("pause");
	return 0;
}



