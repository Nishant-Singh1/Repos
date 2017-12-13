#pragma once

/*Header file defining the template class to implement vector operations*/

#include<vector>

using namespace std;

template<class T>

class VectorStore
{
	vector<T> a1;
	int n;
	public:
		VectorStore()
		{
			a1.assign(3, 0);														//initialise the vector to a 3D origin point
		}
	void enterdata();
	void printdata();
	int checkdata();
	void setdim(int a) { n = a; };
	float dist_calc(VectorStore<T> y);
	int getdim() { return n; };
	void updatesize(int n) { a1.resize(n, 0);}
	template<class T> VectorStore<T> operator + (VectorStore<T> y)	//operator overloading to perform addition using '+'
	{
		VectorStore<T> z;
		getdim() > y.getdim() ? z.setdim(getdim()) : z.setdim(y.getdim());
		z.updatesize(z.getdim());
		updatesize(z.getdim());
		y.updatesize(z.getdim());
		for (int i = 0;i < z.getdim();i++)
		{
			z.a1[i] = a1[i] + y.a1[i];
		}
		return z;
	}
	template<class T> VectorStore<T> operator - (VectorStore<T> y)	//operator overloading to perform subtraction using '-'
	{
		VectorStore<T> z;
		getdim() > y.getdim() ? z.setdim(getdim()) : z.setdim(y.getdim());
		z.updatesize(z.getdim());
		updatesize(z.getdim());
		y.updatesize(z.getdim());
		for (int i = 0;i < z.getdim();i++)
		{
			z.a1[i] = a1[i] - y.a1[i];
		}
		return z;
	}
	template<class T> VectorStore<T> operator * (VectorStore<T> y)	//operator overloading to perform dot product calculation using '*'
	{
		VectorStore<T> z;
		getdim() > y.getdim() ? z.setdim(getdim()) : z.setdim(y.getdim());
		z.updatesize(z.getdim());
		updatesize(z.getdim());
		y.updatesize(z.getdim());
		for (int i = 0;i < z.getdim();i++)
		{
			z.a1[i] = a1[i] * y.a1[i];
		}
		return z;
	}
	template<class T> VectorStore<T> operator ^ (VectorStore<T> y)	//operator overloading to perform cross product calculation using '^'
	{
		VectorStore<T> z;
		if (getdim()>3 || y.getdim()>3)
		{
			cout << "\nCross product cannot be calculated, yet, for vectors with a dimensionality greater than 3.";
			return z;
		}
		else
		{
			VectorStore<T> z;
			getdim() > y.getdim() ? z.setdim(getdim()) : z.setdim(y.getdim());
			z.updatesize(z.getdim());
			z.a1[0] = (a1[1])*(y.a1[2]) - (a1[2])*(y.a1[1]);
			z.a1[1] = (-a1[0])*(y.a1[2]) + (a1[2])*(y.a1[0]);
			z.a1[2] = (a1[0] * y.a1[1]) - (a1[1])*(y.a1[0]);
			return z;
		}
	}
};																					//class to store vector data

template<class T> void VectorStore<T>::enterdata()									//member function to accept input data
{
	
	int i;
	cout << "\nEnter the dimensionality of the vector: ";
	cin >> n;
	if (n > 3)
	{
		a1.resize(n,0);
	}
	cout << "\nEnter vector points: ";
	for (i = 0;i < n;i++)
	{
		cin >> a1[i];
	}
}																					

template<class T> void VectorStore<T>::printdata()									//member function to display data
{
	int i;
	cout << "\nThe vector, with dimensionality " << n << ", is: ";
	for (i = 0;i < n;i++)
	{
		cout << a1[i] << "\t";
	}
}																					

template<class T>int VectorStore<T>::checkdata()									//member function to check data type
{
	if (typeid(T) == typeid(char))
		return 1;
	else return 0;
}

template <class T> float VectorStore<T>::dist_calc(VectorStore<T> y)				//member function for distance calculation
{
	T z=0;
	int size;
	n > y.getdim() ? size = n : size = y.getdim();
	if(getdim()>y.getdim())
	y.updatesize(getdim());
	else a1.resize(y.getdim(),0);
	for (int i = 0;i < size;i++)
	{
		z += (a1[i] - y.a1[i]) * (a1[i] - y.a1[i]);
	}
	return sqrt(z);
}