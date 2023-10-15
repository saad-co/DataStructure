#include <iostream>
using namespace std;


void towerOfHanoi(int n, char s, char a, char tar) {
    if (n == 1) {
        cout << "Move disc 1 from tower " << s << " to tower " << tar << "." << endl;
        return;
    }
    towerOfHanoi(n - 1, s, tar, a);
    cout << "Move disc " << n << " from tower " << s << " to tower " << tar << "." << endl;
    towerOfHanoi(n - 1, a, s, tar);
}

int main() {
    int n = 20; // Number of plates
    char s = 'A', a = 'B', tar = 'C';
    towerOfHanoi(n, s, a, tar);
    return 0;
}
