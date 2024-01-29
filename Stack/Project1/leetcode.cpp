//#include<iostream>
//#include<stack>
//using namespace std;
//
//bool isValid(string s)
//{
//	stack<char> mystack;
//
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s[i] == '(')
//			mystack.push(s[i]);
//		if (s[i] == ')')
//		{
//			for (int i = 0; i < mystack.size(); i++)
//			{
//				if (mystack.top() == '(')
//				{
//					mystack.pop();
//				}
//				else
//				{
//					return false;
//				}
//			}
//		}
//		bool med_flag = false;
//		if (s[i] == '{')
//		{
//			for (int i = 0; i < mystack.size(); i++)
//			{
//				if (mystack.top() == '(')
//				{
//					mystack.pop();
//				}
//				else
//				{
//					mystack.push(s[i]);
//				}
//			}
//		}
//		//     med_op++;
//		if (s[i] == '}')
//		{
//			for (int i = 0; i < mystack.size(); i++)
//			{
//				if (mystack.top() == '(' || mystack.top() == '{')
//				{
//					mystack.pop();
//				}
//			}
//		}
//
//		//     med_cl++;
//		if (s[i] == '[')
//		{
//			for (int i = 0; i < mystack.size(); i++)
//			{
//				if (mystack.top() == '{' || mystack.top() == '(')
//				{
//					mystack.pop();
//				}
//				else
//				{
//					mystack.push(s[i]);
//				}
//			}
//		}
//		//     lar_op++;
//		bool flag = false;
//		if (s[i] == ']')
//		{
//			for (int i = 0; i < mystack.size(); i++)
//			{
//				if (mystack.top() == '{' || mystack.top() == '(')
//				{
//					mystack.pop();
//				}
//				else if (mystack.top() == '[')
//				{
//					flag = true;
//					mystack.pop();
//				}
//			}
//			if (flag != true)
//			{
//				return false;
//			}
//		}
//	}
//
//	return mystack.empty();
//}
//
//
//int main()
//{
//	if (isValid("()[]{}"))
//	{
//		cout << "ok";
//	}
//	else
//		cout << "not ok";
//
//}


//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<Set>
//using namespace std;
//
//int findSecondLargest(int n, vector<int>& arr)
//{
//	int flag = -1;
//	for (int i = 0; i < arr.size()-1; i++)
//	{
//		if (arr[i] == arr[i + 1])
//		{
//			flag = 1;
//		}
//	}
//	if (flag == -1)
//		return -1;
//	// Write your code here.
//	sort(arr.begin(), arr.end());
//	for (auto iter : arr)
//	{
//		cout << iter << " ";
//	}
//	int max = arr[arr.size() - 1];
//	cout <<endl<< "max: " << max << endl;
//	int sec = -1000;
//	//for (auto iter : arr)
//	//{
//	for (int i = 0; i < n-1; i++)
//	{
//		if (arr[i] < arr[i + 1] && arr[i + 1] < max)
//		{
//			sec = arr[i + 1];
//			cout << "in if: " << endl;
//		}
//	}
//	cout << "Sec: " << sec;
//	//}
//	return sec;
//
//}





//bool buddyStrings(string s, string goal)
//{
//	int n = s.length();
//	int m = goal.length();
//
//	// If lengths are different, we can't swap to make them equal
//	if (n != m) {
//		return false;
//	}
//
//	// If both strings are equal, check if there are any repeated characters
//	if (s == goal) {
//		unordered_set<char> seen;
//		for (char ch : s) {
//			if (seen.count(ch)) {
//				return true;
//			}
//			seen.insert(ch);
//		}
//		return false;
//	}
//
//	// Find the first pair of indices where the characters differ
//	int first = -1;
//	int second = -1;
//	for (int i = 0; i < n; ++i) {
//		if (s[i] != goal[i]) {
//			if (first == -1) {
//				first = i;
//			}
//			else if (second == -1) {
//				second = i;
//			}
//			else {
//				// More than two indices differ, can't swap to make them equal
//				return false;
//			}
//		}
//	}
//
//	// If we found two differing indices, check if swapping makes them equal
//	if (first != -1 && second != -1) {
//		if (s[first] == goal[second] && s[second] == goal[first]) {
//			return true;
//		}
//		else {
//			return false;
//		}
//	}
//
//	// No differing indices found
//	return false;
//}


//int main()
//{
//	vector<int> nums = {-3,-3,-3,-3,-3,-3,-3};
//	int val = findSecondLargest(7, nums);
//	cout << "value returned: " << val << endl;
	//cout << "second largest value is: " << val << endl;




	////if (buddyStrings("mandi", "manki"))
	//	cout << "ok";
	//else
	//	cout << "not";
//}