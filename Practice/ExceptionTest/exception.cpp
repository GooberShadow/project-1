#include <iostream>
#include <string>

using namespace std;

int divide(int x, int y)
{
	if (y == 0)
	{
		throw string("An exception occured. Divide by zero");
	}
	return x/y;
}

int main()
{
	try
	{
		cout << "4/2 " << divide(4, 2) << endl;
		cout << "3/0 " << divide(3, 0) << endl;
	}
	catch(string e)
	{
		cout << e << endl;
	}
	return 0;
}
