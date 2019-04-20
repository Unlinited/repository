#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）
int Find_Num(int a[],int y) {
	int num = 0;
	for (int i = 0; i < y; i++) {
		num ^= a[i];  //两个相同的数异或结果为0
	}
	return num;
}
int main() {
	int a[9] = { 1,1,2,3,3,4,4,5,5 };
	printf("%d\n", Find_Num(a, 9));   //数组的传递
	system("pause");
	return 0;

}