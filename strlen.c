#include<stdio.h>
#include<stdlib.h>
strlen(char* string) {
	if (*string == '\0')
		return 0;
	else
		return 1 + strlen(string + 1);
}
strlen_(char* string) {
	int count = 0;
	while (*string++) {
		count++;
	}
	return count;
}
int main() {
	char* string = "haohaoxuexi" ;
	printf("�ݹ���ã�%d\n", strlen(string));
	printf("�ǵݹ���ã�%d\n", strlen_(string));
	system("pause");
	return 0;
}