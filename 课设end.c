#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int purch[1000];//���Ԥ����Ʒ���� i, j;
int product[1000];//���Ԥ����Ʒ����
int offer[1000][1000];//����Ż���Ʒ������
int cost[1000][1000];//�Żݺ�ļ۸�
int  s;//����s���Ż����
void init() {

	memset(offer, 0, sizeof(offer)); //����Щ��ʼ��
	memset(purch, 0, sizeof(purch));
	memset(product, 0, sizeof(product));
}
void mod(){
	int i, j;
	int c, t, p;//t��ʾ�Ż���Ʒ�������Ʒ��������,p��ʾ����Ʒ��ϵ��Żݼ�
	printf("�����뻨�ı�ź͵���:");
	scanf("%d %d", &c, &purch[1]);
	printf("�����뻨ƿ�ı�ź͵���:");
	scanf("%d %d", &c, &purch[2]);
	printf("�м����Ż����:");
	scanf("%d", &s);
	for (i = 1; i <= s; i++) {
		printf("========================\n");
		printf("��%d���Ż����\n", i);
		printf("�Ż�����к��м�����Ʒ:");
		scanf("%d", &t);
		for (j = 1; j <= t; j++) {
			printf("��%d���Żݵ���Ʒ�ı�ź���Ŀ:", j);
			scanf("%d %d", &c, &p);
			offer[i][c] = p;//��i���Ż�����б��Ϊc����Ʒ������ 
		}
		printf("�Żݺ���ܼ�Ϊ:");
		scanf("%d", &offer[i][0]);//����0�±���i���Ż���ϵ��ܼ۸� 
	}
}
void input(){
	printf("*****������Ҫ����Ļ��ͻ�ƿ������:");
	for (int i = 1; i <= 2; i++) {
		scanf("%d", &product[i]);
	}
}
void mincost() {
	int i, min,sum;
	int A, B;
	min = 0;
	sum = 0;
	//����������Ŀ
	int j, k;
	for (j = 0; j <= product[1]; j++) {
		for (k = 0; k <= product[2]; k++) {
			cost[j][k] = j * purch[1] + k * purch[2];//������������µļ۸�
			sum = cost[j][k];
			//�������Żݵļ۸�
			for (i = 1; i <= s; i++) {//����s���Ż����
				A = j - offer[i][1];//��ԭ�����蹺���������ȥ�ﵽ�Żݵ�����
				B = k - offer[i][2];
				min = cost[A][B] + offer[i][0];//��ȥ�Ż�֮�������ļ۸�����Ż������ļ۸�
				if (A >= 0 && B >= 0 && (min < cost[j][k])) {
					cost[j][k] = min;
				}
			}
		}
	}
	//printf("�Żݺ�ļ۸�Ϊ:%d\n", cost[product[1]][product[2]]);
	printf("  ����Ļ�������   ����ƿ����          ԭ�з���           ��С����\n");
	printf("%8d%18d%19d%21d\n", product[1], product[2], sum, cost[product[1]][product[2]]);
}
int main() {
	int i = 1;
	init();
	mod();
	while (1) {
		input();
		system("cls");
		mincost();
		printf("���˳�����0,������������������\n");
		scanf("%d", &i);
		if (i == 0) {
			printf("exit\n");
			break;
		}
	}
	system("pause");
	return 0;
}