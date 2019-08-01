#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int purch[1000];//存放预购商品单价 i, j;
int product[1000];//存放预购商品数量
int offer[1000][1000];//存放优惠商品价数据
int cost[1000][1000];//优惠后的价格
int  s;//共有s种优惠组合
void init() {

	memset(offer, 0, sizeof(offer)); //对这些初始化
	memset(purch, 0, sizeof(purch));
	memset(product, 0, sizeof(product));
}
void mod(){
	int i, j;
	int c, t, p;//t表示优惠商品组合中商品的种类数,p表示此商品组合的优惠价
	printf("请输入花的编号和单价:");
	scanf("%d %d", &c, &purch[1]);
	printf("请输入花瓶的编号和单价:");
	scanf("%d %d", &c, &purch[2]);
	printf("有几种优惠组合:");
	scanf("%d", &s);
	for (i = 1; i <= s; i++) {
		printf("========================\n");
		printf("第%d种优惠组合\n", i);
		printf("优惠组合中含有几种商品:");
		scanf("%d", &t);
		for (j = 1; j <= t; j++) {
			printf("第%d个优惠的商品的编号和数目:", j);
			scanf("%d %d", &c, &p);
			offer[i][c] = p;//第i种优惠组合中编号为c的商品的数量 
		}
		printf("优惠后的总价为:");
		scanf("%d", &offer[i][0]);//利用0下标存第i种优惠组合的总价格 
	}
}
void input(){
	printf("*****请输入要购买的花和花瓶的数量:");
	for (int i = 1; i <= 2; i++) {
		scanf("%d", &product[i]);
	}
}
void mincost() {
	int i, min,sum;
	int A, B;
	min = 0;
	sum = 0;
	//遍历所有数目
	int j, k;
	for (j = 0; j <= product[1]; j++) {
		for (k = 0; k <= product[2]; k++) {
			cost[j][k] = j * purch[1] + k * purch[2];//计算正常情况下的价格
			sum = cost[j][k];
			//计算有优惠的价格
			for (i = 1; i <= s; i++) {//遍历s种优惠组合
				A = j - offer[i][1];//在原有所需购买的数量减去达到优惠的数量
				B = k - offer[i][2];
				min = cost[A][B] + offer[i][0];//减去优惠之后数量的价格加上优惠数量的价格
				if (A >= 0 && B >= 0 && (min < cost[j][k])) {
					cost[j][k] = min;
				}
			}
		}
	}
	//printf("优惠后的价格为:%d\n", cost[product[1]][product[2]]);
	printf("  购买的花朵数量   购买花瓶数量          原有费用           最小费用\n");
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
		printf("若退出输入0,继续请输入其他数字\n");
		scanf("%d", &i);
		if (i == 0) {
			printf("exit\n");
			break;
		}
	}
	system("pause");
	return 0;
}