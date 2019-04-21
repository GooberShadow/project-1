#include <iostream>

using namespace std;

int main(){

int size = 10;
cout << "enter size";
cin >> size;

int* dArr = NULL;
dArr = new int[size];

for (int i = 0; i < size; i++)
{
	dArr[i] = i;
	cout << dArr[i] << endl;
}


int arr[10];
for(int i = 10; i < 20; i++)
{
	arr[i] = i;
	cout << arr[i] << endl;
}

int x = 4;
int y = 5;

delete [] dArr;
dArr = NULL;

return 0;

}
