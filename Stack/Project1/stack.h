//#ifndef STACK_h
//#define STACK_h
//#include<iostream>
//using namespace std;
//
//template<class T>
//class Stack
//{
//private:
//	int capacity;
//	int top;
//	T* data;
//	void resize(int new_size)
//	{
//		T* new_arr = new T[new_size];
//		for (int i = 0; i < this->capacity; i++)
//		{
//			new_arr[i] = data[i];
//		}
//		data = new_arr;
//		capacity = new_size;
//	}
//public:
//	Stack();
//	Stack(Stack& other);
//	bool isfull();
//	bool isempty();
//	void push(T val);
//	T pop();
//	T stacktop();
//	~Stack();
//};
//
//template<class T>
//Stack<T>::Stack(Stack& other)
//{
//	if (this->data != nullptr)
//	{
//		delete[] data;
//		data = nullptr;
//	}
//	for (int i = 0; i < capacity; i++)
//	{
//		data[i] = other.data[i];
//	}
//	top = other.top;
//	capacity = other.capacity;
//}
//
//
//template<class T> 
//Stack<T>::Stack()
//{
//	capacity = 0;
//	top = 0;
//	data = nullptr;
//}
//
//template<class T>
//Stack<T>::~Stack()
//{
//	if (!data)
//		return;
//	delete[] data;
//	capacity = 0;
//	data = nullptr;
//	top = 0;
//}
//
//template<class T>
//bool Stack<T>::isfull()
//{
//	if (top == capacity)
//	{
//		return true;
//	}
//	else
//		return false;
//}
//template<class T>
//bool Stack<T>::isempty()
//{
//	return top == 0;
//}
//template<class T>
//void Stack<T>::push(T val)
//{
//	if (isfull())
//	{
//		resize(capacity == 0 ? 1 : capacity * 2);
//	}
//	data[top++] = val;
//
//}
//
//template<class T>
//T Stack<T>::pop()
//{
//	if (isempty())
//		//throw runtime_error ("stack is empty");      // use try and catch in main otherwise it will produce the run time error 
//		cout << "stack is empty: " << endl;
//	//if (top > 0 && top == capacity / 4)
//	//{
//	//	resize(capacity / 2);
//	//}
//	return data[--top];
//}
//template<class T>
//T Stack<T>::stacktop()
//{
//	if (isempty())
//		throw "stack is empty";
//	return data[top - 1];
//}
//#endif
//
