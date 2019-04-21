#include <iostream>
using namespace std;

int Exponent(int x);
int AddTen(int y);

int main(){
int a = 2;
int b = 1;

int input = 5;
int answer = 0;

answer = Exponent(input);

return 0;
}

int Exponent(int x)
{
	x = x*x;
	x = AddTen(x);
	int var1 = 4;
	int var2 = 4;
	return x;
}

int AddTen(int y)
{
	y = y + 10;
	int c = 3;
	int d = 3;
	return y;
}
