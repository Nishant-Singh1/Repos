/*Menu-driven driver program*/

#include<iostream>
#include<conio.h>
#include"Template_Class.h"

using namespace std;

int main()
{
	VectorStore<float> a, b, q;
	float m;
	try
	{
		if (a.checkdata() || b.checkdata())
			throw 1;
	}
	catch (...)
	{
		cout << "\nThe data type of the class is incompatible with vector operations.";
		_getch();
		exit(0);
	}
	int ch;
	char cho;
	a.enterdata();
	b.enterdata();
	cout << "Enter your choice (1-4): \n";																		//menu
	cout << "1. Vector Addition\n2. Vector Subtraction\n3. Vector Dot Product\n4. Vector Cross Product\n5. Distance between vectors";
	do
	{
		cout << "\n\nChoice: ";
		cin >> ch;
		switch (ch)
		{
		case 1: q = a + b;
				q.printdata();
				break;
		case 2:	q = a - b;
				q.printdata();
				break;
		case 3: q = a * b;
				q.printdata();
				break;
		case 4: q = a ^ b;
				if(q.getdim())
				q.printdata();
				break;
		case 5: m = a.dist_calc(b);
				cout << "\nThe distance between the vectors is: " << m << ".";
				break;
		default: cout << "\nIncorrect choice! Check again.";
				break;
		}
		cout << "\n\nFurther operations required? (Y or N) - ";
		cin >> cho;
	}while (cho == 'Y' || cho == 'y');
	return 0;
}