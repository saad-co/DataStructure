#ifndef TASK2_H
#define TASK2_H
#include<iostream>
using namespace std;

template<typename T>
class stack
{
private:
	T* arr;
	int size;
	int top;
	void resize()
	{
		int new_size = size ? size * 2 : 1;

		T* new_arr = new T[new_size];
		for (int i = 0; i < top; i++)
		{
			new_arr[i] = arr[i];
		}
		delete[] arr;
		arr = new_arr;
		new_arr = nullptr;
		size = new_size;
	}

	void shrink()
	{
		cout << "in shrink: " << endl;
		int new_size = size / 2;
		T* new_arr = new T[new_size];
		for (int i = 0; i < top; i++)
		{
			new_arr[i] = arr[i];
		}
		delete[] arr;
		arr = new_arr;
		new_arr = nullptr;
		size = new_size;
	}


public:
	stack();
	void print();
	bool isfull();
	bool isempty();
	void push(T val);
	T pop();
	int get_size();
	~stack();
};

template<class T>
stack<T>::stack()
{
	arr = nullptr;
	size = 0;
	top = 0;
	//arr = new int[size];
}

template<class T>
void stack<T>::print()
{
	for (int i = 0; i < top; i++)
	{
		cout << arr[i] << endl;

	}
	/*cout << "elements: " << top<<endl;
	cout << "total index: " << size<<endl;*/
}

template<class T>
bool stack<T>::isfull()
{
	return top == size;
}

template<class T>
bool stack<T>::isempty()
{
	return top == 0;
}

template<class T>
void stack<T>::push(T val)
{
	if (isfull())
		this->resize();

	arr[top++] = val;
}

template<class T>
T stack<T>::pop()
{
	if (top <= size / 4)
		shrink();
	if (!isempty())
		return arr[top--];
}

template<class T>
int stack<T>::get_size()
{
	return top;
}

template<class T>
stack<T>::~stack()
{
	if (arr != nullptr)
	{
		delete[]arr;
		arr = nullptr;
		top = 0;
		size = 0;
	}
}

#endif