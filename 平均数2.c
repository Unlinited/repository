#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int  avr(int a,int b) {
    int  num = (a + b) >> 1;
	return num;
}
int avr_(int a, int b) {
	int num_ = a + ((a - b) / 2);
	return num_;
}

int main() {
	int  a, b = 0.0;
	scanf("%d %d", &a, &b);
	printf("%d\n", avr(a, b));
	printf("%d\n", avr_(a, b));
	system("pause");
	return 0;

}