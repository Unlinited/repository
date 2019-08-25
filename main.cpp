#include<iostream>
using namespace std;


namespace test {

	namespace n1 {
		int add(int a, int b)
		{
			cout << "1\n";
			return a + b;
		}
	}


	namespace n2 {
		int add(int a, int b)
		{
			cout << "2\n";
			return a + b;
		}
	}
}


namespace n2 {
	int add(int a, int b)
	{
		cout << "3\n";
		return a + b;
	}
}

int main1()
{
	cout << n2::add(1, 2)<<endl;
	
	cout << test::n1::add(2, 3);
	return 0;
}