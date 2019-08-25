#include<iostream>
#include<stdlib.h>
using namespace std;

void func(int a = 10,int b = 20,int c = 30 )
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}



int Add(int a,int b)
{
	return a + b;
}
double Add(double a, double b)
{
	return  a + b;
	
}
int main2()
{
	func();
	cout << endl;
	func(2);
	cout << endl;
	func(3, 4);
	cout << endl;
	func( 5,6,7);


	cout<<Add(1,2)<<endl;
	cout<<Add(10.0,2.0);
	system("pause");
	return 0;
}