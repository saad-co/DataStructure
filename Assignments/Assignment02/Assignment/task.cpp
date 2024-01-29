#include <iostream>
#include <string>

using namespace std;
struct CourseNode
{
    string courseNumber; 
    string grade;        
    CourseNode *next;   
};

struct StudentData
{
    string name;     
    CourseNode *head; 
};

struct StudentNode
{
    int rollNo;        
    StudentData data;  
    StudentNode *prev; 
    StudentNode *next; 
};

class StudentList
{
private:
    StudentNode head;

public:
    StudentList() : head()
    {
        head.rollNo = -1;
        head.next = &head;
        head.prev = &head;
        head.data.head = nullptr;
    }
    ~StudentList()
    {
        StudentNode *current = head.next;
        while (current != &head)
        {
            StudentNode *next = current->next;
            delete current;
            current = next;
        }
    }

    bool addStudent(int roll, const char *nam)
    {
        if (head.next == &head)
        {
            StudentNode *temp = new StudentNode;
            temp->rollNo = roll;
            temp->data.name = string(nam);
            head.next = temp;
            temp->next = &head;
            temp->prev = &head;
            temp->data.head = nullptr;
            return true;
        }
        StudentNode *temp = head.next;
        while (temp != &head) 
        {
            if (temp->rollNo == roll)
            {
                cout << "Roll NO already exist: " << endl;
                return false;
            }
            temp = temp->next;
        }
        StudentNode *curr = head.next; 
        while (curr->next != &head)
        {
            curr = curr->next;
        }
        StudentNode *temp2 = new StudentNode;
        curr->next = temp2;
        temp2->prev = curr;
        temp2->next = &head;
        head.prev = temp2;
        temp2->rollNo = roll;
        temp2->data.name = string(nam);
        temp2->data.head = nullptr;
        return true;
    }
    void displayStudent(int rollNo)
    {
        StudentNode *temp = head.next;
        while (temp != &head)
        {
            if (temp->rollNo == rollNo)
            {
                cout << "-----------------Displaying student data-----------------\n\n";
                cout << "Name of the Student is: " << temp->data.name << endl;
                cout << "Roll no of student data: " << temp->rollNo << endl;

                if (temp->data.head != nullptr)
                {
                    CourseNode *courseTemp = temp->data.head;
                    while (courseTemp != nullptr)
                    {
                        cout << "Course: " << courseTemp->courseNumber << ", Grade: " << courseTemp->grade << endl;
                        courseTemp = courseTemp->next;
                    }
                }

                cout << "-----------------------------------------------\n";
                return;
            }
            temp = temp->next;
        }

        cout << "No student found with roll number " << rollNo << "." << endl;
    }

    bool removeStudent(int roll)
    {
        if (head.next == &head)
        {
            cout << "list is already empty: " << endl;
            return false;
        }
        else
        {
            StudentNode *temp = head.next;
            while (temp != &head)
            {
                if (temp->rollNo == roll)
                {
                    StudentNode *back = temp->prev;
                    back->next = temp->next;
                    temp->next->prev = back;
                    temp->next = nullptr;
                    temp->prev = nullptr;
                    delete temp;
                    cout << "Student with roll no " << roll << " is removed " << endl;
                    return true;
                }
                temp = temp->next;
            }
        }
        cout << "No student found with this roll number: " << endl;
        return false;
    }
    void updateStudent(int roll, const char *newCourse, const char *grade)
    {
        if (head.next == &head)
        {
            cout << "List is already empty." << endl;
            return;
        }
        else
        {
            StudentNode *temp = head.next;
            while (temp != &head)
            {
                if (temp->rollNo == roll)
                {
                    CourseNode *c_node = new CourseNode;
                    c_node->courseNumber = string(newCourse);
                    c_node->grade = string(grade);
                    if (temp->data.head == nullptr)
                    {
                        temp->data.head = c_node;
                        temp->data.head->next = nullptr;
                    }
                    else
                    {
                        c_node->next = temp->data.head;
                        temp->data.head = c_node;
                    }
                    cout << "Course added successfully." << endl;
                    return;
                }
                temp = temp->next;
            }
        }
        cout << "No student found with roll number " << roll << "." << endl;
        return;
    }
    void displayAllStudent(int order)
    {
        if (order == 0)
        {
            StudentNode *actual = head.next;
            int curr = -1000;
            while (actual != &head)
            {
                int min = 1000;
                StudentNode *temp = head.next;
                while (temp != &head)
                {
                    if (temp->rollNo < min && temp->rollNo > curr)
                    {
                        min = temp->rollNo;
                    }
                    temp = temp->next;
                }
                StudentNode *temp2 = head.next;
                while (temp2 != &head)
                {
                    if (temp2->rollNo == min)
                    {
                        displayStudent(temp2->rollNo);
                        curr = min;
                    }
                    temp2 = temp2->next;
                }
                actual = actual->next;
            }
        }
        else if (order == 1)
        {
            StudentNode *actual = head.next;
            int curr = 1000;
            while (actual != &head)
            {
                int min = -1000;
                StudentNode *temp = head.next;
                while (temp != &head)
                {
                    if (temp->rollNo > min && temp->rollNo < curr)
                    {
                        min = temp->rollNo;
                    }
                    temp = temp->next;
                }
                StudentNode *temp2 = head.next;
                while (temp2 != &head)
                {
                    if (temp2->rollNo == min)
                    {
                        displayStudent(temp2->rollNo);
                        curr = min;
                    }
                    temp2 = temp2->next;
                }
                actual = actual->next;
            }
        }
        else
        {
            cout << "order is not correct choose from 0,1: " << endl;
        }
    }
};

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    StudentList studentList;

    int choice;
    do
    {
        cout << "\n------------- Menu -------------" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Remove Student" << endl;
        cout << "3. Update Student" << endl;
        cout << "4. Display Student" << endl;
        cout << "5. Display All Students (Ascending Order)" << endl;
        cout << "6. Display All Students (Descending Order)" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int roll;
            char name[50];
            cout << "Enter Roll Number: ";
            cin >> roll;
            cout << "Enter Name: ";
            cin.ignore(); 
            cin.getline(name, sizeof(name));
            if (studentList.addStudent(roll, name))
                cout << "Student added successfully." << endl;
            break;
        }
        case 2:
        {
            int roll;
            cout << "Enter Roll Number to Remove: ";
            cin >> roll;
            if (studentList.removeStudent(roll))
                cout << "Student removed successfully." << endl;
            break;
        }
        case 3:
        {
            int roll;
            char newCourse[10], grade[3];
            cout << "Enter Roll Number: ";
            cin >> roll;
            cout << "Enter New Course: ";
            cin >> newCourse;
            cout << "Enter Grade: ";
            cin >> grade;
            studentList.updateStudent(roll, newCourse, grade);
            break;
        }
        case 4:
        {
            int roll;
            cout << "Enter Roll Number to Display: ";
            cin >> roll;
            studentList.displayStudent(roll);
            break;
        }
        case 5:
            studentList.displayAllStudent(0); 
            break;
        case 6:
            studentList.displayAllStudent(1);
            break;
        case 0:
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}
