#include <iostream>
#include <string>
using namespace std;

bool areAnagrams(const string &str1, const string &str2)
{
    string lowercaseStr1 = str1;
    string lowercaseStr2 = str2;
    for (char &ch : lowercaseStr1)
    {
        ch = tolower(ch);
    }
    for (char &ch : lowercaseStr2)
    {
        ch = tolower(ch);
    }

    int count1[256] = {0};
    int count2[256] = {0};

    for (char ch : lowercaseStr1)
    {
        count1[ch]++;
    }
    for (char ch : lowercaseStr2)
    {
        count2[ch]++;
    }

    for (int i = 0; i < 256; ++i)
    {
        if (count1[i] != count2[i])
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string str1 = "gram";
    string str2 = "silent";

    if (areAnagrams(str1, str2))
    {
        cout << "The given strings are anagrams." << endl;
    }
    else
    {
        cout << "The given strings are not anagrams." << endl;
    }

    return 0;
}
