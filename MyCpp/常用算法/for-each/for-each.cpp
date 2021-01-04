#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

void printf1(int val)
{
	cout << val << " ";
}



void test()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);

	}

	for_each(v.begin(), v.end(), printf1);
	
}



int main()
{
	test();


	system("pause");
	return 0;

}