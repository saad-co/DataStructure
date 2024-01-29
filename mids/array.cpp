#include <iostream>
using namespace std;

class Array
{
    int total_size;
    int used_size;
    int *arr;
public:
    Array()
    {
        total_size = 10;
        used_size = 5;
        arr = new int[total_size];
    }
    void set()
    {
        int num;
        for (int i = 0; i < used_size; i++)
        {
            cout << "Enter the value for " << i << " index :";
            cin >> num;
            arr[i] = num;
        }
    }
    int get(int index)
    {
        if (index <= used_size)
        {
            return arr[index];
        }
        return -1;
    }
    void push(int ele)
    {
        if (used_size == total_size)
        {
            resize();
        }
        arr[used_size] = ele;
        used_size++;
    }
    void insert(int index, int value)
    {
        if (used_size == total_size)
        {
            resize();
        }
        if (index < used_size)
        {

            for (int i = used_size; i >= index; i--)
            {
                arr[i + 1] = arr[i];
            }
            arr[index] = value;
            used_size++;
        }
        else
        {
            cout << "invalid index";
        }
    }
    void del(int index)
    {
        for (int i = index + 1; i < used_size; i++)
        {
            arr[i - 1] = arr[i];
        }
        used_size--;
    }
    void resize()
    {
        total_size = total_size * 2;
        int *temp = new int[total_size];
        for (int i = 0; i <= used_size; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }
    void Asensort()
    {
        int temp[total_size];
        for (int i = 0; i < used_size; i++)
        {
            for (int j = 0; j < used_size; j++)
            {
                if (arr[i] < arr[j])
                {
                    temp[i] = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp[i];
                }
            }
        }
    }
    void Desensort()
    {
        int temp[total_size];
        for (int i = 0; i < used_size; i++)
        {
            for (int j = 0; j < used_size; j++)
            {
                if (arr[i] > arr[j])
                {
                    temp[i] = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp[i];
                }
            }
        }
    }
    void search(int ele)
    {
        int flag = -1;
        for (int i = 0; i < used_size; i++)
        {
            if (arr[i] == ele)
            {
                flag = i;
                break;
            }
        }
        if (flag != -1)
        {
            cout << "Element found at " << flag << " index" << endl;
        }
        else
        {
            cout << "Element not found" << endl;
        }
    }
    void binary(int ele)
    {
        Asensort();
        int mid;
        int start = 0;
        int end = total_size - 1;
        int flag = -1;
        while (start <= end)
        {
            mid = start + (end - start) / 2;
            if (ele == arr[mid])
            {
                flag = mid;
            }
            if (ele > arr[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        if (flag != -1)
        {
            cout << "Element found at " << mid << " index" << endl;
        }
        else
        {
            cout << "Element not found" << endl;
        }
    }
    void display()
    {
        cout << endl
             << "Array elements are :";
        for (int i = 0; i < used_size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl
             << "used size :" << used_size << " total size :" << total_size << endl;
    }
    void copy(Array &obj)
    {
        used_size = obj.used_size;
        total_size = obj.total_size;
        delete[] arr;
        arr = new int[total_size];
        for (int i = 0; i < used_size; i++)
        {
            arr[i] = obj.arr[i];
        }
    }
    ~Array()
    {
        if (arr != nullptr)
        {
            delete[] arr;
            arr = nullptr;
        }
        total_size = 0;
        used_size = 0;
    }
};
int main()
{
    Array a, b;
    int choice;
    while (true)
    {
        cout << "Menu:\n";
        cout << "1. Set\n";
        cout << "2. Get\n";
        cout << "3. Push\n";
        cout << "4. Insert\n";
        cout << "5. Delete\n";
        cout << "6. Ascending Sort\n";
        cout << "7. Descending Sort\n";
        cout << "8. Linear Search\n";
        cout << "9. Binary Search\n";
        cout << "10. Copy\n";
        cout << "11. Display\n";
        cout<< "12. B Dispaly\n";
        cout << "0. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            a.set();
            break;
        case 2:
            int g_ele;
            cout << "enter the element you want to get :";
            cin >> g_ele;
            a.get(g_ele);
            break;
        case 3:
            int p_ele;
            cout << "enter the element you want to push in array :";
            cin >> p_ele;
            a.push(p_ele);
            break;
        case 4:
            int i_ele, index;
            cout << "enter the index and element you want to insert in array :";
            cin >> index >> i_ele;
            a.insert(index, i_ele);
            break;
        case 5:
            int d_ele;
            cout << "enter the element you want to delete from array :";
            cin >> d_ele;
            a.del(d_ele);
            break;
        case 6:
            a.Asensort();
            break;
        case 7:
            a.Desensort();
            break;
        case 8:
            int l_ele;
            cout << "enter the element you want to search from array :";
            cin >> l_ele;
            a.search(l_ele);
            break;
        case 9:
            int b_ele;
            cout << "enter the element for binary search from array :";
            cin >> b_ele;
            a.binary(b_ele);
            break;
        case 10:
            b.copy(a);
            b.display();
            break;
        case 11:
            a.display();
            break;
            case 12:
            b.display();
            break;
        case 0:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }

        cout << endl;
    }
    return 0;
}