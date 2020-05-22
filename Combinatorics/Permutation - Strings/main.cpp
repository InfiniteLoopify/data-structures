#include <iostream>
#include <cstring>
using namespace std;

void mySwap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void anagram(string& str, int index = 0)
{
    if(index >= str.length())
    {
        cout << str << "\n";
    }
    else
    {
        for(int i = index; i < str.length(); ++i)
        {
            mySwap(&str[i], &str[index]);
            anagram(str, index + 1);
            mySwap(&str[i], &str[index]);
        }
    }
}

int main()
{
    string str;
    cout << "Enter a String: ";
    cin >> str;
    anagram(str);

    return 0;
}
