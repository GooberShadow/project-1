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
#include "tree.c"

using  namespace std;

//Remove duplicates function to remove duplicate nodes
int removeDuplicates(int arr[], int n)
{
	int j = 0;

	for (int i=0; i < n; i++)
	{
    		for(j=i+1; j<n;)
    		{
        		if(arr[i]==arr[j])
       			{
            			for(int k=j; k<n-1; ++k)
				{
                			arr[k] = arr[k+1];
				}
            			--n;
        		}
        		else
			{
            			++j;
			}
    		}
	}

	return n;
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
		
		getline( f, input, '\0' );

		f.close();
	}
	//get input from keyboard until ctrl d
	if (argc == 1)
	{
		while (getline(cin, line))
		{
			input += " " + line;
		}
	}

	//ASSIGNING THE STRING FROM INPUT INTO A VECTOR ARRAY
	stringstream ssin(input);
	istream_iterator<string> begin(ssin);
	istream_iterator<string> end;
	vector<string> vstring(begin, end);

	//OBTAINING SIZE FOR TREE ARRAY
	vector<string>::iterator it;

	int treeIterator = 0;
	
	for(it = vstring.begin(); it != vstring.end(); ++it)
	{
		treeIterator++;
	}
	
	const int size = treeIterator;

	int treeArray[size];
	
	//INITIALIZE EACH ELEMENT OF TREE ARRAY TO 0
	for(int i = 0; i < size; i++)
	{
		treeArray[i] = 0;
	}
	
	treeIterator = 0;

	//FILLING TREE ARRAY WITH INTEGER LENGTH VALUES
	for(it = vstring.begin(); it != vstring.end(); ++it)
	{
		treeArray[treeIterator] = vstring.at(treeIterator).length();
		++treeIterator;
	}

	treeIterator = 0;

	//REMOVING DUPLICATES FROM TREEARRAY
	int newSize = sizeof(treeArray) / sizeof(treeArray[0]);
	
	newSize = removeDuplicates(treeArray, newSize);


	BinarySearchTree b;
	int level = 0;
	for(int i = 0; i < newSize; i++)
	{
		b.buildTree(treeArray[i]);
	}

	//Calling different traversals for file.output
	if(argc == 2)
	{
		//get filename and convert to char array
		string fileName = argv[1];

		string inorderFile = fileName + ".inorder";
		string preorderFile = fileName + ".preorder";
		string postorderFile = fileName + ".postorder";

		int inorderN = inorderFile.length();
		char charArrayInorder[inorderN+1];
		strcpy(charArrayInorder, inorderFile.c_str());

		int preorderN = preorderFile.length();
		char charArrayPreorder[preorderN+1];
		strcpy(charArrayPreorder, preorderFile.c_str());
		
		int postorderN = postorderFile.length();
		char charArrayPostorder[postorderN+1];
		strcpy(charArrayPostorder, postorderFile.c_str());

		//open new file for outputting to
		fstream file;
		file.open(charArrayInorder, ios::out);
		string fileLine;

		streambuf* stream_buffer_cout = cout.rdbuf();

		streambuf* stream_buffer_file = file.rdbuf();

		cout.rdbuf(stream_buffer_file);

		//cout to that file
		cout << "in-order traversal " << endl;
		cout << "-------------------" << endl;
		b.printInorder(level, vstring);
		cout << endl << endl;

		cout.rdbuf(stream_buffer_cout);
		file.close();

		//open file for preorder printing
		file.open(charArrayPreorder, ios::out);

		cout.rdbuf(stream_buffer_file);

		cout << "preorder traversal " << endl;
		cout << "-------------------" << endl;
		b.printPreorder(level, vstring);	
		cout << endl << endl;

		cout.rdbuf(stream_buffer_cout);
		file.close();

		//open file for postorder printing
		file.open(charArrayPostorder, ios::out);

		cout.rdbuf(stream_buffer_file);

		cout << "postorder traversal " << endl;
		cout << "-------------------" << endl;
		b.printPostorder(level, vstring);
		cout << endl << endl;

		cout.rdbuf(stream_buffer_cout);
		file.close();

	}

	//Repeat for out.output
	if(argc == 1)
	{

		fstream file;
		file.open("out.inorder", ios::out);
		string fileLine;

		streambuf* stream_buffer_cout = cout.rdbuf();

		streambuf* stream_buffer_file = file.rdbuf();

		cout.rdbuf(stream_buffer_file);

	
		cout << "in-order traversal " << endl;
		cout << "-------------------" << endl;
		b.printInorder(level, vstring);
		cout << endl << endl;

		cout.rdbuf(stream_buffer_cout);
		file.close();

		file.open("out.preorder", ios::out);

		cout.rdbuf(stream_buffer_file);

		cout << "preorder traversal " << endl;
		cout << "-------------------" << endl;
		b.printPreorder(level, vstring);	
		cout << endl << endl;

		cout.rdbuf(stream_buffer_cout);
		file.close();

		file.open("out.postorder", ios::out);

		cout.rdbuf(stream_buffer_file);

		cout << "postorder traversal " << endl;
		cout << "-------------------" << endl;
		b.printPostorder(level, vstring);
		cout << endl << endl;

		cout.rdbuf(stream_buffer_cout);
		file.close();
	}
	
	return 0;
}
