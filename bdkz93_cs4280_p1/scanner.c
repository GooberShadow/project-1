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
#include <algorithm>
#include "scanner.h"
//void scanner(vector<string> &vect, int size);
using namespace std;

//variable to keep track of line numbers
int totalLineNum = 0;

//Function for else statement in TOKEN FOR LOOP
bool isSubstring(string s1, string s2)
{
	int M = s1.length();
	int N = s2.length();
	
	for(int i = 0; i <= N- M; i++)
	{
		int j;
		for(j = 0; j < M; j++)
		{
			if (s2[i + j] != s1[j])
			{
				break;
			}
		}
		if(j == M)
		{
			return true;
		}
	}
	return false;
}

//Function for checking if a string is an id token
bool isID(string s)
{
	for(unsigned int i = 0; i < s.length(); i++)
	{
		if(isalnum(s[i]) == false)
		{
			return false;
		}
		return true;
	}
	return false;
};

//Function for checking if a string is a digit
bool isINT(string s)
{
	for(unsigned int i = 0; i < s.length(); i++)
	{
		if(isdigit(s[i]) == false)
		{
			return false;
		}
		return true;
	}
	return false;
};

//Function for SCANNER
void scanner(vector<string> &vect, int size, string input)
{
	//Formatting for else statement.
	for(unsigned int i = 0; i < input.length(); i++)
	{
		if(input[i] == '\n')
		{
			totalLineNum++;
		}
	}

	string strArr[totalLineNum];
	int positionArr[totalLineNum];
	int iterator = 0;
	
	//while loop to assign position of each newline to positionArr
	while(iterator < totalLineNum)
	{
		for(unsigned int i = 0; i < input.length(); i++)
		{
			if(input[i] == '\n')
			{
				positionArr[iterator] = i;
				iterator++;
			}
		}
	}

	//inputs each line into each element of strArr
	for(int i = 0; i < totalLineNum; i++)
	{
		strArr[i] = input.substr(positionArr[i], (positionArr[i+1] - positionArr[i]));
	}
	
	//variable for else statement
	string s1;
	
	//FOR LOOP FOR THE TOKENS
	for(int i = 0; i < size; i++)
	{
		if(vect.at(i) == "iter")
		{
			cout << "iterTKN" << endl;
		}
		else if(vect.at(i) == "void")
		{
			cout << "voidTKN" << endl;
		}
		else if(vect.at(i) == "var")
		{
			cout << "varTKN" << endl;
		}
		else if(vect.at(i) == "return")
		{
			cout << "returnTKN" << endl;
		}
		else if(vect.at(i) == "scan")
		{
			cout << "scanTKN" << endl;
		}
		else if(vect.at(i) == "print")
		{
			cout << "printTKN" << endl;
		}
		else if(vect.at(i) == "program")
		{
			cout << "programTKN" << endl;
		}
		else if(vect.at(i) == "cond")
		{
			cout << "condTKN" << endl;
		}
		else if(vect.at(i) == "then")
		{
			cout << "thenTKN" << endl;
		}
		else if(vect.at(i) == "let")
		{
			cout << "letTKN" << endl;
		}
		else if(vect.at(i) == "int")
		{
			cout << "intTKN" << endl;
		}
		else if(islower(vect.at(i).at(0)) && isID(vect.at(i)))
		{
			cout << "IDTKN" << endl;
		}
		else if(isINT(vect.at(i)))
		{
			cout << "IntegerTKN" << endl;
		}
		else if(vect.at(i) == "=")
		{
			cout << "AssignmentTKN" << endl;
		}
		else if(vect.at(i) == "<")
		{
			cout << "LessThanTKN" << endl;
		}
		else if(vect.at(i) == ">")
		{
			cout << "GreaterThanTKN" << endl;
		}
		else if(vect.at(i) == ":")
		{
			cout << "ColonTKN" << endl;
		}
		else if(vect.at(i) == "+")
		{
			cout << "AdditionTKN" << endl;
		}
		else if(vect.at(i) == "-")
		{
			cout << "SubtractionTKN" << endl;
		}
		else if(vect.at(i) == "*")
		{
			cout << "MultiplicationTKN" << endl;
		}
		else if(vect.at(i) == "/")
		{
			cout << "DivisionTKN" << endl;
		}
		else if(vect.at(i) == "%")
		{
			cout << "ModulusTKN" << endl;
		}
		else if(vect.at(i) == ".")
		{
			cout << "DotTKN" << endl;
		}
		else if(vect.at(i) == "(")
		{
			cout << "LeftParenthesisTKN" << endl;
		}
		else if(vect.at(i) == ")")
		{
			cout << "RightParenthesisTKN" << endl;
		}
		else if(vect.at(i) == ",")
		{
			cout << "CommaTKN" << endl;
		}
		else if(vect.at(i) == "{")
		{
			cout << "LeftCurlyBraceTKN" << endl;
		}
		else if(vect.at(i) == "}")
		{
			cout << "RightCurlyBraceTKN" << endl;
		}
		else if(vect.at(i) == ";")
		{
			cout << "SemiColonTKN" << endl;
		}
		else if(vect.at(i) == "[")
		{
			cout << "LeftBracketTKN" << endl;
		}
		else if(vect.at(i) == "]")
		{
			cout << "RightBracketTKN" << endl;
		}
		else
		{
			//assign s1 to current word
			s1 = vect.at(i);
			//for loop through total lines
			for(int j = 0; j < totalLineNum; j++)
			{
				//call substring to check if s1 is in the line number j
				if(isSubstring(s1, strArr[j]))
				{
					cout << "Scanner Error: " << s1 << " at line #" << j+1 << endl;
					break;
				} 
			}
		}
	}
	cout << "EOFTKN" << endl;
}
