#include <iostream>

using namespace std;

int main()
{
	char input[10];
	cout << "enter in a word less than 10 char. " << endl;
	cin >> input;
	//Check after gathering input.
	for(int i = 0; i < 10; i++)
	{
		if (input[i] == '#')
		{
			cout << "Found the error at user input" << endl;
		}
	}

	for(int i = 0; i < 10; i++)
	{
		if(input[i] == '#')
		{
			cout << endl << "Found the error!" << endl;
		}
		else
		{
			cout << input[i];
		}
	}
	return 0;
}
