#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <iterator>

using namespace std;
//creating the class for binary search tree
class BinarySearchTree
{
private:
	struct tree_node
	{
		tree_node* left;
		tree_node* right;
		int data;
	};
	tree_node* root;
public:
	BinarySearchTree()
	{
		root = NULL;
	}
	
	bool isEmpty() const { return root == NULL; }
	void printInorder(int level, vector<string> &vect);
	void inorder(tree_node* p, int level, vector<string> &vect);
	void printPreorder(int level, vector<string> &vect);
	void preorder(tree_node*, int level, vector<string> &vect);
	void printPostorder(int level, vector<string> &vect);
	void postorder(tree_node*, int level, vector<string> &vect);
	void buildTree(int);
};

//INSERT FUNCTION
void BinarySearchTree::buildTree(int d)
{
	tree_node* t = new tree_node;
	tree_node* parent;
	t->data = d;
	t->left = NULL;
	t->right = NULL;
	parent = NULL;

	//Checking for new tree
	if(isEmpty()) root = t;
	else
	{
		tree_node* curr;
		curr = root;
		//Find the Node's parent
		while (curr)
		{
			parent = curr;
			if (t->data > curr->data) curr = curr->right;
			else curr = curr->left;
		}
		
		if (t->data < parent->data)
			parent->left = t;
		else
			parent->right = t;
	}
}

//INORDER TRAVERSAL
void BinarySearchTree::printInorder(int level, vector<string> &vect)
{
	inorder(root, level, vect);
}

void BinarySearchTree::inorder(tree_node* p, int level, vector<string> &vect)
{
	if (p != NULL)
	{
		if (p->left)
		{
			level += 1;
			inorder(p->left, level, vect);
			level -= 1;
		}
		cout << endl;
		for (int i = 0; i < level; i++)
		{
			cout << "--";
		}
		cout << " " << p->data << " ";
		
		int positionIT = 0;
		vector<string>::iterator it;
		for (it = vect.begin(); it != vect.end(); ++it)
		{
			if((unsigned)p->data == vect.at(positionIT).length())
			{
				cout << vect.at(positionIT) << " ";
			}
			positionIT++;
		}

		if (p->right);
		{
			level += 1;
			inorder(p->right, level, vect);
		}
	}
	else
	{
		return;
	}
}

//PREORDER TRAVERSAL
void BinarySearchTree::printPreorder(int level, vector<string> &vect)
{
	preorder(root, level, vect);
}

void BinarySearchTree::preorder(tree_node* p, int level, vector<string> &vect)
{
	if (p != NULL)
	{
		cout << endl;
		for (int i = 0; i < level; i++)
		{
			cout << "--";
		}
		cout << " " << p->data << " ";
		
		int positionIT = 0;
		vector<string>::iterator it;
		for (it = vect.begin(); it != vect.end(); ++it)
		{
			if((unsigned)p->data == vect.at(positionIT).length())
			{
				cout << vect.at(positionIT) << " ";
			}
			positionIT++;
		}

		if (p->left)
		{
			level += 1;
			preorder(p->left, level, vect);
			level -= 1;
		}
		if (p->right)
		{
			level += 1;
			preorder(p->right, level, vect);
		}
	}
	else
	{
		return;	
	}
}

//POSTORDER TRAVERSAL
void BinarySearchTree::printPostorder(int level, vector<string> &vect)
{
	postorder(root, level, vect);
}

void BinarySearchTree::postorder(tree_node* p, int level, vector<string> &vect)
{
	if (p != NULL)
	{
		if (p->left) 
		{
			level += 1;
			postorder(p->left, level, vect);
			level -= 1;
		}
		if (p->right) 
		{
			level += 1;
			postorder(p->right, level, vect);
			level -= 1;
		}


		cout << endl;
		for (int i = 0; i < level; i++)
		{
			cout << "--";
		}
		cout << " " << p->data << " ";
		
		int positionIT = 0;
		vector<string>::iterator it;
		for (it = vect.begin(); it != vect.end(); ++it)
		{
			if((unsigned)p->data == vect.at(positionIT).length())
			{
				cout << vect.at(positionIT) << " ";
			}
			positionIT++;
		}
	}
	else return;
}

