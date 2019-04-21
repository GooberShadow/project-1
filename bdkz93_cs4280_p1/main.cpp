#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <iterator>
#include <set>
#include "scanner.c"

using  namespace std;

//Function to remove comments from the input
string removeComments(string input)
{
	string str = "&";
	string str2 = "nl";
	int pos = 0;
	int pos2 = 0;
	int pos1 = 0;
	size_t found = input.find(str);
	size_t found2 = input.find(str2);

	if(found != string::npos)
	{
		pos = input.find(str);
	}
	else if(found2 != string::npos)
	{
		cout << "ERROR: Comment terminator nl without the & to begin the comment " << endl;
		//end program
		exit(0);
		return input;
	}
	else
	{
		return input;
	}

	pos2 = input.find(str2);

	pos1 = pos2 - pos;
	pos1 += 2;

	input.erase(pos, (pos1));

	return input;
}

//MAIN
int main(int argc, char *argv[])
{
	string line;
	string input;
	if (argc > 2)
	{
		cout << "Too many arguments" << endl;
	}
	//get input from a file by appending .sp19 to it
	if (argc == 2) 
	{
		string base = argv[1];
		base += ".sp19";

		fstream f(base.c_str(), fstream::in);
		if (f)
		{
			getline( f, input, '\0' );
			f.close();
		}
		else
		{
			f.close();
			cout << "Program error file not found" << endl;
		}
	}
	//get input from keyboard until ctrl d
	
	if (argc == 1)
	{
		while (getline(cin, line))
		{
			input += " \n " + line;
		}
	}

	input = removeComments(input);

	string trueInput = input;
	
	//ASSIGNING THE STRING FROM INPUT INTO A VECTOR ARRAY
	stringstream ssin(input);
	istream_iterator<string> begin(ssin);
	istream_iterator<string> end;
	vector<string> vstring(begin, end);

	//OBTAINING SIZE
	vector<string>::iterator it;

	int theIterator = 0;
	
	for(it = vstring.begin(); it != vstring.end(); ++it)
	{
		theIterator++;
	}
	
	const int size = theIterator;
	
	//Spacing for eaeier readability
	cout << endl;

	//Call scanner function to translate to tokens
	scanner(vstring, size, trueInput);
	
}
