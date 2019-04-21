#include <iostream>
#include <string>

using namespace std;


class Rectangle {
	private :
		int width, height;
	public:
	Rectangle(int width1, int height1)
	{
		width = width1;
		height = height1;
	}
	Rectangle(const Rectangle &ptr)
	{
		width = ptr.width;
		height = ptr.height;
	}Rectangle *r_ptr;
	~Rectangle()
	{
		cout << "DESTROYED " << endl;
		r_ptr = NULL;
		delete r_ptr;
	}
	int getHeight()
	{
		return height;
	}
	int getWidth()
	{
		return width;
	}
};

void Pass(Rectangle*);
int main()
{
	Rectangle r1(10, 15);
	Rectangle r2 = r1;
	Rectangle *r3;
	Pass(r3);
	cout << "r1 width = " << r1.getWidth() << ", r1 height = " << r1.getHeight();

	return 0;
}

void Pass(Rectangle *ptr)
{

	cout << "here lies the ptr. " << ptr;
	ptr = NULL;	
	delete ptr;
};
