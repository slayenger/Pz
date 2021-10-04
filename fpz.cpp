#include <iostream>
using namespace std;

class Mass
{
private:
	int *arr;
	int size;

public:

	Mass();
	Mass(int size)
	{
		this->size = size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}
	Mass(const Mass& other)
	{
		this->size = other.size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			this->arr[i] = other.arr[i];
		}
	}
	~Mass()
	{
		delete[] arr;
	}
	void Print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << i << " - " << arr[i] << endl;
		}
		cout << endl;
	}
	void SetVal(int i, int val)
	{
		if (i >= 0 && i < size && val <= 100 && val >= -100)
		{
			arr[i] = val;
		}
		else
		{
			cout << "Incorrect data" << endl;
		}
	}
	int GetVal(int i)
	{
		if (i < size && i >=0) 
		{
			return arr[i];
		}
		else
		{
			cout << "Error get value" << endl;
		}
		
	}
	void AddVal(int newval)
	{
		if (newval >= -100 && newval <= 100)
		{
			size = size + 1;
			int* NewArr = new int[size];
			for (int i = 0; i < size-1; i++)
			{
			NewArr[i] =arr[i];
			}
			
			NewArr[size-1] = newval;
			arr = NewArr;
		}
		else
		{
			cout << "Incorrect data" << endl;
		}
		
	}
	void Plus(Mass& other)
	{
		if (size <= other.size)
		{
			for (int i = 0; i < size; i++)
			{
				arr[i] += other.arr[i];
			}
		}
		else
		{
			for (int i = 0; i < other.size; i++)
			{
				arr[i] += other.arr[i];
			}
		}
	}
	void Minus(Mass& other)
	{
		if (size <= other.size)
		{
			for (int i = 0; i < size; i++)
			{
				arr[i] -= other.arr[i];
			}
		}
		else
		{
			for (int i = 0; i < other.size; i++)
			{
				arr[i] -= other.arr[i];
			}
		}
	}
};

int main()
{
	Mass a(5);
	a.SetVal(1, 100);
	a.SetVal(0, 4);
	a.Print();
	Mass b(a); //copy
	b.Print();
	a.AddVal(10);
	a.Print();
	
	//Mass d(3);
	//d.SetVal(1, 10);
	//d.Minus(a);
	////d.Plus(a);
	//d.Print();
	return 0;
}

