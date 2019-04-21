#include <iostream>

using namespace std;

int main()
{
	int input1 = 0;
	int input2 = 0;
	int answer1 = 0;
	int answer2 = 0;
	int answer3 = 0;
	int remainder = 0;

	const int MAX_INT = 2147483647;
	const int MIN_INT = -2147483648;
	
	cout << "Enter the first number" << endl;
	cin >> input1;
	cout << "Enter the non-zero second number" << endl;
	cin >> input2;

	cout << input1 << endl;
	cout << input2 << endl;
	if(input2 == 0)
	{
		cout << "Your second number was 0 and you cannot divide by 0!" << endl;
	}
	//start of else
	else
	{
		//case where input1 is negative and input 2 is positive.
		
		if((input1 < 0 && input2 > 0))
		{
			answer1 = input1 + input2;
			
			cout << "Here is the addition: " << answer1 << endl;
			
			if((MIN_INT/input1) < input2)
			{
				cout << "You entered too large a number! The multiplication was overflowed!" << endl;
			}
			else
			{
				answer2 = input1 * input2;
				cout << "Here is the multiplication: " << answer2 << endl;

				answer3 = input1/input2;
				remainder = input1%input2;
				cout << "Here is the division: " << answer3 << " with remainder " << remainder << endl;
			}		
		}
		else if((input1 > 0 && input2 < 0))
		{
			answer1 = input1 + input2;
			cout << "Here is the addition: " << answer1 << endl;

			if((MIN_INT/input2) < input1)
			{
				cout << "You enetered too large a number! The multiplication overflowed!" << endl;
			}
			else
			{
				answer2 = input1 * input2;
				cout << "Here is the multiplication: " << answer2 << endl;

				answer3 = input1/input2;
				remainder = input1%input2;
				cout << "Here is the division: " << answer3 << " with remainder " << remainder << endl;
			}
			
		}
		else if(input1 < 0 && input2 < 0)
		{
			if(MIN_INT +(-input1) > input2)
			{
				cout << "Your numbers were too small and there was an overflow!" << endl;
			}
			else if(MIN_INT + (-input2) > input1)
			{
				cout << "Your numbers were too small and there was an overflow!" << endl;
			}
			else
			{
				answer1 = input1 + input2;
				
				cout << "Here is the addition: " << answer1 << endl;
				
				if((-(MAX_INT/input1)) < (-input2))
				{
					cout << "The multiplication was overflowed!" << endl;
				}
				else if((-(MAX_INT/input2)) < (-input1))
				{
					cout << "The multiplication was overflowed!" << endl;
				}
				else
				{
					answer2 = input1 *input2;
					cout << "Here is the multiplication: " << answer2 << endl;
					answer3 = input1/input2;
					remainder = input1%input2;
					cout << "Here is the division: " << answer3 << "with remainder " << remainder << endl;
				}
			}
		}
		else
		{
			if(MAX_INT - input1 < input2)
			{
				cout << "You entered too large a number! Addition There was overflow!" << endl;
			}

			else if(MAX_INT - input2 < input1)
			{
				cout << "You entered too large a number! Addition 2 There was overflow!" << endl;			
			}
		
			else
			{
				answer1 = input1 + input2;

				cout << "Here is the addition: " << answer1 << endl;	
			
				if(MAX_INT/input1 < input2)
				{
					cout << "You entered too large a number! The multiplication was overflowed!" << endl;
				}
				else if(MAX_INT/input2 < input1)
				{
					cout << "You entered too large a number! The Multiplication 2 was overflowed!" << endl;
				}
				else
				{
					answer2 = input1 * input2;
					cout << "Here is the multiplication: " << answer2 << endl;

					answer3 = input1/input2;
					remainder = input1%input2;
					cout << "Here is the division: " << answer3 << " with remainder " << remainder << endl;
				}
			}
		}
	}
	return 0;
}
