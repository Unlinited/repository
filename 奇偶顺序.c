#include<stdio.h>
#include<stdlib.h>
int main() {
	int a[9] = { 1,2,3,4,5,6,7,8,9 };
	int i = 0, j = 0;
	int temp;
	while (a[i++] % 2 && i <= 8);
	while (a[j--] % 2 == 0 && j >= 0);
	while (i <= j) {
		temp = a[i - 1];
		a[i - 1] = a[j + 1];
		a[j + 1] = temp;
		while (a[i++] % 2);
		while (a[j--] % 2 == 0);
    }
	for (i = 0; i < 9; i++) {
		printf("%d  ", a[i]);
	}
	system("pause");
	return 0;
}