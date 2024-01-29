#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

class StudentMaxHeap;
class Student
{
    friend class StudentMaxHeap;

private:
    int rollNo;  // Student’s roll number
    double cgpa; // Student’s CGPA

public:
    // Constructor for Student class
    Student(int roll, double gpa) : rollNo(roll), cgpa(gpa) {}
    Student() : rollNo(0), cgpa(0.0){};
};
class StudentMaxHeap
{
private:
    Student *st;  // Array of students which will be arranged like a Max Heap
    int currSize; // Current number of students present in the heap
    int maxSize;  // Maximum number of students that can be stored in the heap

    // Helper functions
    void heapifyUp(int i)
    {
        while (i > 0 && (st[parent(i)].cgpa < st[i].cgpa))
        {
            swap(st[parent(i)], st[i]);
            i = parent(i);
        }
    }

    void heapifyDown(int i)
    {
        int maxIndex = i;
        int l = leftChild(i);
        int r = rightChild(i);

        if (l < currSize && (st[l].cgpa > st[maxIndex].cgpa))
        {
            maxIndex = l;
        }

        if (r < currSize && (st[r].cgpa > st[maxIndex].cgpa))
        {
            maxIndex = r;
        }

        if (i != maxIndex)
        {
            swap(st[i], st[maxIndex]);
            heapifyDown(maxIndex);
        }
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int leftChild(int i)
    {
        return 2 * i + 1;
    }

    int rightChild(int i)
    {
        return 2 * i + 2;
    }

public:
    // Constructor
    StudentMaxHeap(int size) : currSize(0), maxSize(size)
    {
        st = new Student[maxSize];
    }

    // Destructor
    ~StudentMaxHeap()
    {
        delete[] st;
    }

    // Checks whether the heap is empty or not
    bool isEmpty()
    {
        return currSize == 0;
    }

    // Checks whether the heap is full or not
    bool isFull()
    {
        return currSize == maxSize;
    }

    // Inserts a new student record into the Max Heap
    bool insert(int rollNo, double cgpa)
    {
        if (isFull())
        {
            cout << "Heap is full. Cannot insert more students." << endl;
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
            cout << "Heap is empty. Cannot remove student." << endl;
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
        if (isEmpty())
        {
            cout << "Heap is empty." << endl;
            return;
        }

        queue<int> q;
        q.push(0);

        while (!q.empty())
        {
            int currentIndex = q.front();
            q.pop();

            cout << "Roll No: " << st[currentIndex].rollNo << ", CGPA: " << st[currentIndex].cgpa << endl;

            int leftIndex = leftChild(currentIndex);
            int rightIndex = rightChild(currentIndex);

            if (leftIndex < currSize)
            {
                q.push(leftIndex);
            }

            if (rightIndex < currSize)
            {
                q.push(rightIndex);
            }
        }
    }

    int height()
    {
        return log2(currSize) + 1;
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
            cout << "height of the tree is: " << maxHeap.height();
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
