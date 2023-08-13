//#include<iostream>
//#include<cmath>
//using namespace std;
//
//class Polynomial
//{
//private:
//	int* arr;
//	int power;
//	int coff;
//	int max_index;
//public:
//
//	Polynomial(int max_degree) :max_index(max_degree), power(0), coff(0)
//	{
//		arr = new int[max_degree + 1];
//		for (int i = 0; i <= max_degree; i++)
//		{
//			arr[i] = 0;
//		}
//	}
//
//
//	Polynomial(const Polynomial& obj)
//	{
//		if (this->arr != nullptr)
//		{
//			delete[]arr;
//			arr = nullptr;
//		}
//		this->power = obj.power;
//		this->coff = obj.coff;
//		this->max_index = obj.max_index;
//		arr = new int[max_index + 1];
//		for (int i = 0; i <= max_index; i++)
//		{
//			this->arr[i] = obj.arr[i];
//		}
//	}
//
//
//	//void checking_info()
//	//{
//	//	cout << "the max degree of the polynomial is: " << this->max_index;
//	//}
//
//
//	int get_degree() const
//	{
//		int max = 0;
//		for (int i = 0; i < max_index; i++)
//		{
//			if (arr[i] > arr[i + 1])
//			{
//				max = i;
//			}
//		}
//		return max;
//	}
//
//
//	Polynomial& operator =(const Polynomial& other)
//	{
//		if (this == &other)
//		{
//			cout << "self assignment is done: " << endl;
//			return *this;
//		}
//		else
//		{
//			if (this->arr != nullptr)
//			{
//				delete[]arr;
//				arr = nullptr;
//			}
//			this->power = other.power;
//			this->coff = other.coff;
//			this->max_index = other.max_index;
//			arr = new int[max_index];
//			for (int i = 0; i <= max_index; i++)
//			{
//				this->arr[i] = other.arr[i];
//			}
//
//		}
//		return *this;
//
//	}
//
//
//	void add_term(int cofficient, int degree)
//	{
//		try
//		{
//			if (degree > max_index)
//			{
//				throw "degree is greater than the allowed: ";
//			}
//			arr[degree] = cofficient;
//		}
//		catch (exception& e)
//		{
//			cerr << endl << e.what() << endl;
//		}
//	}
//
//
//	void remove_term(int degree)
//	{
//		arr[degree] = 0;
//	}
//
//	void set_cofficient(int cofficient, int degree)
//	{
//		//arr[degree] = cofficient;
//		add_term(cofficient, degree);
//	}
//
//	friend ostream& operator<<(ostream& out, const Polynomial& obj);
//
//
//	Polynomial operator +(const Polynomial& other)
//	{
//		int loop = 0;
//		if (this->max_index > other.max_index)
//		{
//			loop = max_index;
//		}
//		else
//		{
//			loop = other.max_index;
//		}
//		Polynomial n = (this->max_index > other.max_index) ? *this : other;
//		Polynomial l = (this->max_index > other.max_index) ? other : *this;
//		for (int i = 0; i < l.max_index; i++)
//		{
//			//printf("value of this array: %d\n", arr[i]);
//			//cout << arr[i] << endl;
//			//n.arr[i] = this->arr[i] + other.arr[i];
//			n.arr[i] += l.arr[i];
//		}
//		return n;
//	}
//
//	double operator ()(double val) const
//	{
//		double result = NULL;
//		for (int i = 0; i < this->max_index; i++)
//		{
//			result += this->arr[i] * pow(val, i);
//
//		}
//		return result;
//	}
//
//	Polynomial& operator*(const Polynomial& other)
//	{
//		int deree = this->max_index + other.max_index;
//		Polynomial n(deree);
//		for (int i = 0; i <= this->max_index; i++)
//		{
//			for (size_t j = 0; j <= other.max_index; j++)
//			{
//				n.arr[i + j] += this->arr[i] * other.arr[j];
//			}
//		}
//		return n;
//	}
//
//
//
//	~Polynomial()
//	{
//		if (arr)
//		{
//			delete[]arr;
//			arr = nullptr;
//		}
//	}
//
//};
//
//ostream& operator<<(ostream& out, const Polynomial& obj)
//{
//	bool flag = false;        // to prevent printing the first '+'
//	for (int i = obj.max_index; i >= 0; i--)
//	{
//		if (obj.arr[i])
//		{
//			if (obj.arr[i] > 0 && flag)
//				cout << "+";
//			flag = true;
//			cout << obj.arr[i];
//			if (i != 0)
//				cout << "x^" << i;;
//		}
//	}
//
//	return out;
//}
//
//
//
//
//int main()
//{
//
//	Polynomial p1(2);
//	p1.add_term(2, 0);
//	p1.add_term(1, 1);
//	p1.add_term(4, 2);
//	cout << p1<<endl;
//	Polynomial p2(1);
//	p2.add_term(3, 0);
//	p2.add_term(3, 1);
//	cout << p2<<endl;
//
//
//	cout << p1 + p1 << endl;
//	//cout << p1 * p2 << endl;
//	//int val = p1.get_degree();
//	//cout << val << endl;
//	//cout << p1(2);
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//	//Polynomial obj1(5);
//	//obj1.set_cofficient(15, 3);
//	//obj1.set_cofficient(20, 1);
//	//obj1.set_cofficient(30, 0);
//	//int val = obj1.get_degree();
//	//cout << obj1.get_degree();
//	/*cout << val<<endl;*/
//
//	//Polynomial obj2(8);
//	//obj2.set_cofficient(15, 3);
//	//obj2.set_cofficient(20, 1);
//	//obj2.set_cofficient(20, 6);
//	//obj2.set_cofficient(4, 7);
//	//cout << obj2<<endl;
//	//Polynomial obj3(1);
//	//obj3.set_cofficient(1, 1);
//	//obj3.set_cofficient(1, 0);
//	//cout << "_____________________________" << endl;
//	//cout << obj3*obj3;
//
//	//cout << obj1 * obj2 << endl;
//	//cout << obj1;
//	//cout << obj1(3.0);
//
//	//obj1 + obj2;
//	//cout << obj1 + obj2;
//
//	//cout << obj1;
//	//obj1.checking_info();
//
//
//	//Polynomial obj2(obj1);
//	//obj2.checking_info();
//
//
//
//	return 0;
//}