//#include<iostream>
//#include "task.h"
//using namespace std;
//
//
//template<typename T>
//void reverseArray(T* arr, int size)
//{
//	stack<T> s;
//	for (int i = 0; i < size; i++)
//	{
//		s.push(arr[i]);
//
//	}
//	//s.print();
//	for (int i = 0; i < size; i++)
//	{
//		//cout<<endl<<"-----------" << s.pop()<<endl;
//		arr[i] = s.pop();
//	}
//
//	
//}
//int main()
//{
//	int size = 5;
//	int* arr = new int[size];
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = i+10;
//
//	}
//
//
//	cout << "before: " << endl;
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << endl;
//	}
//
//
//	reverseArray(arr, size);
//	cout << "after: " << endl;
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << endl;
//	}
//
//
//	delete[]arr;
//	arr = nullptr;
//
//
//
//	return 0;
//}