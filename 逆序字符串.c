#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
void Reverse_Word(char *str ,int i,int j) {//�ַ����е��ʵ�����
	char temp;
	for (; i < j; i++, j--) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}
void Reverse_String(char *str) {
	int i;
	int start, end = 0;
	for (i = 0; str[i]; i++) {
		if (str[i] == ' ') {
			end = i - 1;
			Reverse_Word(str, start, end);
		}
		start = i + 1;
	}
	Reverse_Word(str, start, i-1);  //�ַ��������һ����������
	Reverse_Word(str, 0, i-1);      //�ַ���������
}
int main() {
	char str[] = { "student a am i" };
	printf("student a am i\n");
	Reverse_String(str);
	puts(str);
	system("pause");
	return 0;

}