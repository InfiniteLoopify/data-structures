#include <iostream>
#include <cstring>
using namespace std;

string comb;
int combination(const string &str, int size, int index = 0)
{
    if(comb.length() >= size)
        cout << comb << "\n";
    else
    {
        for(int i = index; i < str.length(); ++i)
        {
            comb.push_back(str[i]);
            combination(str, size, i + 1);
            comb.pop_back();
        }
    }
}

int main()
{
    string str = "ABCDE";
    combination(str, 3);

    return 0;
}
