//#include<iostream>
//#include "stack.h"
//using namespace std;
//
//template<typename T>
//void reverseArray(T* arr, int size)
//{
//	Stack<T> s;
//	for (int i = 0; i < size; i++)
//	{
//		s.push(arr[i]);
//	}
//	for (int i = 0; i < size; i++)
//	{
//		arr[i] = s.pop();
//	}
//
//
//}
//
//
//int main()
//{
//	int arr[5]{ 0 };
//	for (int i = 0; i < 15; i++)
//	{
//		arr[i] = rand() % 50;
//	}
//	for (int i = 0; i < 15; i++)
//	{
//		//arr[i] = rand() % 50;
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	//reverseArray(arr, 5);
//
//	Stack<int> s;
//	for (int i = 0; i < 15; i++)
//	{
//		s.push(arr[i]);
//	}
//
//
//	//int val = s.pop();
//	//cout << s.pop();
//	//cout << s.pop();
//	//cout << s.pop();
//	//cout << s.pop();
//	//cout << s.pop();
//
//	try
//	{
//
//		for (int i = 0; i < 15; i++)
//		{
//			//int val = s.pop();
//			cout << s.pop() << " ";
//		}
//	}
//	catch (exception& e)
//	{
//		cerr << e.what() << endl;
//	}
//
//
//
//
//	//cout << s.pop();
//	//for (int i = 0; i < 5; i++)
//	//{
//	//	arr[i] = s.pop();
//	//}
//
//	//for (int i = 0; i < 5; i++)
//	//{
//	//	//arr[i] = rand() % 50;
//	//	cout << arr[i];
//	//}
//
//	//Stack<int> obj;
//	//obj.push(20.0);
//	////int val = obj.stacktop();
//	//cout << obj.pop();
//	return 0;
//
//
//}