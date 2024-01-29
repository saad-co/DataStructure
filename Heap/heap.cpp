#include <iostream>
using namespace std;

class StudentMaxHeap;
class Student
{
    friend class StudentMaxHeap;
    Student(int roll, double gp)
    {
        rollNo = roll;
        cgpa = gp;
    }
    Student() : rollNo(-1), cgpa(0.0){};

private:
    int rollNo;  // Student’s roll number
    double cgpa; // Student’s CGPA
};
class StudentMaxHeap
{
private:
    Student *st;  // Array of students which will be arranged like a Max Heap
    int currSize; // Current number of students present in the heap
    int maxSize;  // Maximum number of students that can be stored in the heap
    void heapifyUp(int i)
    {
        while (i > 0 && st[getParent(i)].cgpa < st[i].cgpa)
        {
            swap(st[getParent(i)], st[i]);
            i = getParent(i);
        }
    }
    int getParent(int i)
    {
        return i / 2;
    }
    int leftChild(int i)
    {
        return 2 * i + 1;
    }
    int rightChild(int i)
    {
        return 2 * i + 2;
    }
    void heapifyDown(int i)
    {
        int maxIndex = i;
        int l = leftChild(i);
        int r = rightChild(i);
        if (l > 0 && (st[l].cgpa > st[maxIndex].cgpa))
        {
            maxIndex = l;
        }
        if (r > 0 && (st[r].cgpa > st[maxIndex].cgpa))
        {
            maxIndex = r;
        }
        if (i != maxIndex)
        {
            swap(st[maxIndex], st[i]);
            heapifyDown(maxIndex);
        }
    }

public:
    StudentMaxHeap(int size) // Constructor
    {
        currSize = 0;
        maxSize = size;
        st = new Student[size];
    }
    ~StudentMaxHeap() // Destructor
    {
        delete[] st;
        st = nullptr;
    }
    bool isEmpty() // Checks whether the heap is empty or not
    {
        return currSize == 0;
    }
    bool isFull() // Checks whether the heap is full or not
    {
        return currSize == maxSize;
    }
    bool insert(int rollNo, double cgpa)
    {
        if (isFull())
        {
            cout << "heap is full: " << endl;
            return false;
        }
        st[currSize] = Student(rollNo, cgpa);
        heapifyUp(currSize);
        currSize++;
        return true;
    }
    bool removeBestStudent(int &rollNo, double &cgpa)
    {
        if (isEmpty())
        {
            cout << "heap is empty: " << endl;
            return false;
        }
        rollNo = st[0].rollNo;
        cgpa = st[0].cgpa;
        st[0] = st[currSize - 1];
        currSize--;
        heapifyDown(0);
        return true;
    }
    void levelOrder()
    {
        for (int i = 0; i < currSize; i++)
        {
            cout << st[i].cgpa << " ";
        }
        cout << endl;
    }
};

int main()
{
    int choice;
    StudentMaxHeap maxHeap(10);

    do
    {
        cout << "Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Remove\n";
        cout << "3. Display\n";
        cout << "4. height of the heap\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int rollNo;
            double cgpa;
            cout << "Enter Roll No and CGPA of the student: ";
            cin >> rollNo >> cgpa;

            if (maxHeap.insert(rollNo, cgpa))
            {
                cout << "Student inserted successfully.\n";
            }
            else
            {
                cout << "Failed to insert student.\n";
            }
            break;
        }

        case 2:
        {
            int removedRollNo;
            double removedCgpa;

            if (maxHeap.removeBestStudent(removedRollNo, removedCgpa))
            {
                cout << "Removed student - Roll No: " << removedRollNo << ", CGPA: " << removedCgpa << endl;
            }
            else
            {
                cout << "Heap is empty. Cannot remove student.\n";
            }
            break;
        }

        case 3:
            cout << "List of students (Level-order traversal):\n";
            maxHeap.levelOrder();
            break;

        case 4:
            cout << "height of the tree is: ";
            cout << endl;
            break;

        case 5:
            cout << "Exiting the program.\n";
            break;

        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 5);

    return 0;
}
