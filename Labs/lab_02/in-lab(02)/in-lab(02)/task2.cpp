//#include<iostream>
//#include "task.h"
//#include<string>
//using namespace std;
//
//bool isPalindrome(const string& str)
//{
//	stack<char> s;
//	for (int i = 0; i < str.size(); i++)
//	{
//		s.push(str[i]);
//	}
//	bool l = true;
//	for (int i = 0; i < str.size(); i++)
//	{
//		//cout << str[i] << endl;
//		if (str[i] != s.pop())
//		{
//			l = false;
//		}
//	}
//
//	//s.print();
//
//	return l;
//}
//
//int main()
//{
//	string obj = "kabbak";
//	if (isPalindrome(obj))
//		cout << "ok " << endl;
//	else
//		cout << "not: " << endl;
//	return 0;
//}