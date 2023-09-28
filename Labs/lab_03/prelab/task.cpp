#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T1, typename T2>
class cPair
{
private:
    T1 first;
    T2 second;

public:
    cPair() : first(0), second(0) {}
    cPair(T1 first, T2 second) : first(first), second(second) {}
    cPair(const cPair &obj) : first(obj.first), second(obj.second) {}
    T1 getFirst() const { return first; }
    T2 getSecond() const { return second; }
    cPair makePair(T1 first, T2 second)
    {
        cPair obj(first, second);
        return obj;
    }
    cPair &operator=(const cPair &obj)
    {
        first = obj.first;
        second = obj.second;
        return *this;
    }
    bool operator>=(const cPair &obj)
    {
        if (first >= obj.first)
        {
            if (second >= obj.second)
            {
                return true;
            }
        }
        return false;
    }
    bool operator<=(const cPair &obj)
    {
        if (first <= obj.first)
        {
            if (second <= obj.second)
            {
                return true;
            }
        }
        return false;
    }
    bool operator==(const cPair &obj)
    {
        if (first == obj.first)
        {
            if (second == obj.second)
            {
                return true;
            }
        }
        return false;
    }
    bool operator!=(const cPair &obj)
    {
        if (first != obj.first)
        {
            if (second != obj.second)
            {
                return true;
            }
        }
        return false;
    }
    friend ostream &operator<<(ostream &out, const cPair &obj)
    {
        out << obj.first << " " << obj.second;
        return out;
    }
    friend istream &operator>>(istream &in, cPair &obj)
    {
        in >> obj.first >> obj.second;
        return in;
    }
};
int main()
{
    cPair<char, int> pair1, pair2;

    cout << "Enter values for pair1 (T1 T2): ";
    cin >> pair1;
    cout << "pair1: " << pair1 << endl;

    cout << "Enter values for pair2 (T1 T2): ";
    cin >> pair2;
    cout << "pair2: " << pair2 << endl;

    cout << "pair1 >= pair2: " << (pair1 >= pair2) << endl;
    cout << "pair1 <= pair2: " << (pair1 <= pair2) << endl;
    cout << "pair1 == pair2: " << (pair1 == pair2) << endl;
    cout << "pair1 != pair2: " << (pair1 != pair2) << endl;
    return 0;
}