//#include<iostream>
//#include "task2.h"
//using namespace std;
//template<class T>
//stack<T>::stack()
//{
//	arr = nullptr;
//	size = 0;
//	top = 0;
//}
//
//template<class T>
//void stack<T>::print()
//{
//	for (int i = 0; i < top; i++)
//	{
//		cout << arr[i] << endl;
//
//	}
//	cout << "elements: " << top;
//}
//
//template<class T>
//bool stack<T>::isfull()
//{
//	return top == size;
//}
//
//template<class T>
//bool stack<T>::isempty()
//{
//	return top == 0;
//}
//
//template<class T>
//void stack<T>::push(T val)
//{
//	if (isfull())
//		this->resize();
//
//	arr[top++] = val;
//}
//
//template<class T>
//T stack<T>::pop()
//{
//	if (!isempty())
//		return arr[top--];
//	if (top == size / 4)
//		shrink();
//}
//
//template<class T>
//int stack<T>::get_size()
//{
//	return top;
//}
//
//template<class T>
//stack<T>::~stack()
//{
//	if (arr != nullptr)
//	{
//		delete[]arr;
//		arr = nullptr;
//		top = 0;
//		size = 0;
//	}
//}