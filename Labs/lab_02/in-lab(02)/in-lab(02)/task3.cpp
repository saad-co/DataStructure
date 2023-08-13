//#include<iostream>
//#include "task.h"
//#include<string>
//using namespace std;
//
//
//bool check(const string& str)
//{
//	stack<char> s;
//	int open_count = 0;
//	int close_count = 0;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] == '(')
//		{
//			open_count += 1;
//		}
//		else if (str[i] == ')')
//		{
//			close_count += 1;
//		}
//		else
//		{
//			//continue;
//		}
//	}
//	//cout << "open: " << open_count << endl;
//	//cout << "close: " << close_count << endl;
//
//	if (open_count == close_count)
//	{
//		return true;
//
//	}
//	else
//	{
//		return false;
//	}
//
//
//}
//
//
//int main()
//{
//	string str = "(a) + b) * (c - d)";
//	if (check(str))
//		cout << "ok " << endl;
//	else
//		cout << "not: " << endl;
//
//	return 0;
//}