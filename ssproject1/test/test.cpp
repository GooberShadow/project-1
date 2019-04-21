#include <iostream>

using namespace std;

int Send(int var);
int test(int var);

int main()
{
	int x = 4;
	int y = 3;
		
	int z = 5;
	z = Send(x);
	return 0;
}

int Send(int var)
{
	var = test(var);
	return var;
}

int test(int var)
{
	int a = 2;
	int b = 1;
	return a;
}
