#include "iostream"

using namespace std;

class Array
{
	int* ar;		//holds reference of array, created on heap
	int size;		//holds the maximum size of array

public:
	//default constructor
	Array()
	{
		size = 5;						//default size of array
		ar = new int[size];				//allocating array on heap

		for (int i = 0; i < size; i++)
			ar[i] = 0;					//initializing array to default data
	}

	//overloaded constructor. accept the size of array as parameter
	Array(int size)
	{
		this->size = size;				//initializing size of array
		ar = new int[size];				//allocating array on heap

		for (int i = 0; i < size; i++)
			ar[i] = 0;					//initializing array to default data
	}

	//overloaded constructor. accept an array with its size and intialize object's data with them
	Array(int ar[], int size)
	{
		this->size = size;				//initializing size of array
		this->ar = new int[size];		//allocating array on heap

		for (int i = 0; i < size; i++)
			this->ar[i] = ar[i];		//initializing object's array with the data of array passed as argument
	}

	//copy constructor
	Array(const Array& obj)
	{
		this->size = obj.size;			//initializing size of array
		ar = new int[size];				//allocating array on heap

		for (int i = 0; i < size; i++)
			this->ar[i] = obj.ar[i];	//initializing object's array with the data of right-hand side object
	}

	//destructor
	~Array()
	{
		delete[] ar;					//free memory resources allocated on heap 
	}

	//overloaded assignment operator
	Array operator= (const Array& obj)
	{
		if (this != &obj)					//avoiding self assignment of object	
		{
			if (size != obj.size)			//checking the sizes of both object's array
			{
				delete[] ar;				//freeing memory resources allocated on heap

				size = obj.size;			//setting the size of left-hand side object

				ar = new int[size];			//allocating new array on heap for left-hand side object
			}

			for (int i = 0; i < size; i++)
				this->ar[i] = obj.ar[i];	//initializing object's array with the data of right-hand side object
		}

		return *this;
	}

	//overloaded index [] operator for non-constant objects to handle lvalue and rvalue
	int& operator[] (int index)
	{
		if (index >= 0 && index < size)		//bound checking of array's index
		{
			return ar[index];				//returning the legal memory location
		}

		cout << "Array Index is Out-of-Bound" << endl;

		exit(0);							//closing the program (if required)
	}

	//overloaded index [] operator for constant objects to handle only rvalue
	int operator[] (int index) const
	{
		if (index >= 0 && index < size)		//bound checking of array's index
		{
			return ar[index];				//returning the legal memory location
		}

		cout << "Array Index is Out-of-Bound" << endl;

		exit(0);							//closing the program (if required)
	}

	//member function to take input from user for ar
	void getData()
	{
		for (int i = 0; i < size; i++)
		{
			cout << "Enter value " << i + 1 << " = ";
			cin >> ar[i];
		}
	}

	//member function to display ar
	void putData() const
	{
		for (int i = 0; i < size; i++)
		{
			cout << ar[i] << "\t";
		}

		cout << endl;
	}
};

int main()
{
	int a[5] = { 5, 4, 3, 2, 1 };

	Array obj1, obj2(7), obj3(a, 5), obj4(obj3);
	const Array objc(a, 5);

	obj4[3] = 9;

	cout << obj4[3] << endl;

	cout << objc[4] << endl;

	return 0;
