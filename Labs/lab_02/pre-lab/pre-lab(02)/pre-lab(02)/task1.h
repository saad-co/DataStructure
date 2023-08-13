//#ifndef TASK1_H
//#define TASK1_H
//#include<iostream>
//#include<stdexcept>
//using namespace std;
//
//template<typename T>
//class stack
//{
//private:
//	T* arr;
//	int size;
//	int indx;
//
//
//public:
//	void display_stack()const
//	{
//		for (int i = 0; i < indx; i++)
//		{
//			cout << arr[i] << endl;
//		}
//		cout << "total elements: " << indx << endl;
//	}
//
//	stack() :size(5), indx(0)
//	{
//		arr = new int[size];
//		
//	}
//	bool isfull()
//	{
//		return indx == size;
//	}
//	void push(T val)
//	{
//		try
//		{
//			if (isfull())
//			{
//				throw "Stack is full";
//			}
//		}
//		catch (string& e)
//		{
//			cerr << e << endl;
//		}
//		arr[indx++] = val;
//	
//	}
//
//	bool isempty()
//	{
//		return indx == 0;
//	}
//
//	T pop()
//	{
//		try
//		{
//			if (!isempty())
//			{
//				return arr[indx--];
//			}
//			else
//			{
//				throw "Stack is empty: ";
//			}
//		}
//		catch (string& e)
//		{
//			cerr << e << endl;
//		}
//	}
//
//	int get_size()
//	{
//		return indx;
//	}
//	~stack()
//	{
//		if (arr != nullptr)
//		{
//			delete[]arr;
//			arr = nullptr;
//			indx = 0;
//			size = 0;
//		}
//	}
//
//};
//#endif
//
