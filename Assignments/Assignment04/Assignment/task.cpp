#include <iostream>
#include <string>
using namespace std;

class StudentBST;
class StudentNode
{
	friend class StudentBST;

private:
	int rollNo;			// Student’s roll number (must be unique)
	string name;		// Student’s name
	double cgpa;		// Student’s CGPA
	StudentNode *left;	// Pointer to the left subtree of a node
	StudentNode *right; // Pointer to the right subtree of a node
public:
	StudentNode() : rollNo(-1), name(""), cgpa(-1.0), left(nullptr), right(nullptr)
	{
	}
	StudentNode(int r, string str, double g) : rollNo(r), name(str), cgpa(g), left(nullptr), right(nullptr) {}
};
class StudentBST
{
private:
	StudentNode *root; // Pointer to the root node of the BST

	// helper functions
	bool find_roll(const int rn, StudentNode *&base)
	{
		if (base == nullptr)
		{
			return false;
		}
		if (base->rollNo == rn)
		{
			return true;
		}
		return find_roll(rn, base->left) || find_roll(rn, base->right);

		return true;
	}
	StudentNode *findRollAddress(int rn, StudentNode *base)
	{
		if (base == nullptr)
		{
			return nullptr;
		}
		if (base->rollNo == rn)
		{
			return base;
		}
		findRollAddress(rn, base->left);
		findRollAddress(rn, base->right);
	}
	StudentNode *inserting_at_pos(StudentNode *&base, StudentNode *&to_insert)
	{
		if (base == nullptr)
		{
			base = to_insert;
			return base;
		}
		if (base->rollNo > to_insert->rollNo)
		{
			base->left = inserting_at_pos(base->left, to_insert);
		}
		else
		{
			base->right = inserting_at_pos(base->right, to_insert);
		}
		return base;
	}
	void inOrder(StudentNode *s)
	{
		if (s)
		{
			inOrder(s->left);
			cout << s->rollNo << " " << s->name << " " << s->cgpa << endl;
			inOrder(s->right);
		}
	}
	void destroy(StudentNode *&s)
	{
		if (s)
		{
			destroy(s->left);
			destroy(s->right);
			delete s;
			s = nullptr;
		}
	}
	StudentNode *findmin(StudentNode *p)
	{
		while (p->left != nullptr)
		{
			p = p->left;
		}
		return p;
	}
	StudentNode *Delete(StudentNode *root, int key)
	{
		if (root == nullptr)
			return root;
		if (key < root->rollNo)
			root->left = Delete(root->left, key);
		else if (key > root->rollNo)
			root->right = Delete(root->right, key);
		else
		{
			if (root->left == nullptr && root->right == nullptr)
			{
				delete root;
				return nullptr;
			}
			else if (root->left == nullptr)
			{
				StudentNode *temp = root->right;
				delete root;
				return temp;
			}
			else if (root->right == nullptr)
			{
				StudentNode *temp = root->left;
				delete root;
				return temp;
			}
			else
			{
				StudentNode *temp = findmin(root->left);
				root->rollNo = temp->rollNo;
				root->name = temp->name;
				root->cgpa = temp->cgpa;
				root->left = Delete(root->left, temp->rollNo);
			}
		}
		return root;
	}

public:
	StudentBST() // Default constructor
	{
		root = nullptr;
	}

	~StudentBST()
	{
		destroy(root);
	}

	bool insert(int rn, string n, double c)
	{
		bool check = find_roll(rn, root);
		if (check == false)
		{
			StudentNode *new_Stu = new StudentNode(rn, n, c);
			inserting_at_pos(root, new_Stu);
			return true;
		}
		else if (check == true)
		{
			return false;
		}
	}

	void inorder() { inOrder(root); }

	bool search(int rn)
	{
		return find_roll(rn, root);
	}

	bool remove(int rn)
	{
		return Delete(root, rn);
	}
};

void printMenu()
{
	cout << "Menu:" << endl;
	cout << "1. Insert a new student" << endl;
	cout << "2. Search for a student" << endl;
	cout << "3. Remove a student" << endl;
	cout << "4. See the list of all students (sorted by Roll No.)" << endl;
	cout << "5. Quit" << endl;
	cout << "Enter your choice: ";
}
int main()
{
	StudentBST b1;
	int choice;
	int rollNo;
	string name;
	double cgpa;
	do
	{
		printMenu();
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "Enter Roll No." << endl;
			cin >> rollNo;
			while (rollNo < 0)
			{
				cout << "You have entered Invalid RollNo. \nEnter Again: " << endl;
				cin >> rollNo;
			}
			cin.ignore();
			cout << "Enter Name" << endl;
			getline(cin, name);
			cout << "Enter CGPA: " << endl;
			cin >> cgpa;
			while (cgpa < 0 || cgpa > 4.0)
			{
				cout << "You have entered Invalid cgpa. \nEnter Again: " << endl;
				cin >> cgpa;
			}
			if (b1.insert(rollNo, name, cgpa))
			{
				cout << "student added successfully: " << endl;
			}
			else
			{
				cout << "A student with same roll no. already exist: " << endl;
			};
			break;
		case 2:
			cout << "Enter Roll No. to search: ";
			cin >> rollNo;
			if (b1.search(rollNo))
				cout << "Student found!" << endl;
			else
				cout << "Student not found." << endl;
			break;
		case 3:
			cout << "Enter Roll No. to remove: ";
			cin >> rollNo;
			if (b1.remove(rollNo))
				cout << "Student removed successfully." << endl;
			else
				cout << "Student not found." << endl;
			break;
		case 4:
			cout << "List of students (sorted by Roll No.): ";
			b1.inorder();
			cout << endl;
			break;
		case 5:
			cout << "Exiting the program." << endl;
			break;
		default:
			cout << "Invalid choice. Please enter a valid option." << endl;
		}

	} while (choice != 5);
	return 0;
}