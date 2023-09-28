#include <iostream>
using namespace std;
template<typename T1,typename T2>

class cPair{
    T1 first;
    T2 second;
public:
 cPair(){
     first=0;
     second=0;
 }
 
 cPair(T1 v1,T2 v2){
     first=v1;
     second=v2;
 }
 cPair(const cPair &obj){
     first=obj.first;
     second=obj.second;
 }
 cPair makepair(T1 v1,T2 v2){
     return cPair(v1,v2);
 }
 cPair operator=(const cPair & obj){
     if(this!=obj){
         first=obj.first;
         second=obj.second;
     }
     return *this;
 }
  bool operator>=(const cPair& obj)
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
    bool operator<=(const cPair& obj)
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
    bool operator==(const cPair& obj)
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
    bool operator!=(const cPair& obj)
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
friend  ostream& operator<<(ostream &os,const cPair& obj){
    os<<"{"<<obj.first<<","<<obj.second<<"}";
    return os;
}

friend istream& operator>>(istream & in,cPair& obj){
    in>>obj.first>>obj.second;
    return in;
}
};
int main() {
   cPair<int,char> c1;
   cout<<"Default Constructor : "<<c1<<endl;
   
   float v1;
   char v2;
   cout<<"Enter first Value : ";
   cin>>v1;
   cout<<"Enter second Value : ";
   cin>>v2;
   cPair<float,char> c2(v1,v2);
   cout<<"Parametrized Constructor : "<<c2<<endl;
   
   cPair<float,char> copy(c2);
   cout<<"Copy Constructor : "<<copy<<endl;
 
  cPair<char, int> pair1, pair2;

    cout << "Enter values for pair1 (char int): ";
    cin >> pair1;
    cout << "pair1: " << pair1 << endl;

    cout << "Enter values for pair2 (char int): ";
    cin >> pair2;
    cout << "pair2: " << pair2 << endl;

    cout << "pair1 >= pair2: " << (pair1 >= pair2) << endl;
    cout << "pair1 <= pair2: " << (pair1 <= pair2) << endl;
    cout << "pair1 == pair2: " << (pair1 == pair2) << endl;
    cout << "pair1 != pair2: " << (pair1 != pair2) << endl;
    return 0;
}