#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

string protienList = "ACDEFGHIKLMNPQRSTVWY";
string combination;
int count = 0;

void permute()
{
    ofstream out("Combination.txt");
    for(int i = 0; i < protienList.length(); ++i)
    {
        combination.push_back(protienList[i]);
        for(int j = 0; j < protienList.length(); ++j)
        {
            combination.push_back(protienList[j]);
            for(int k = 0; k < protienList.length(); ++k)
            {
                combination.push_back(protienList[k]);
                ++count;
                out << combination << "\n";
                combination.pop_back();
            }
            combination.pop_back();
        }
        combination.pop_back();
    }
}

//void permute2(int index, int length)
//{
//    if(combination.length() >= length)
//    {
//        ++count;
//        cout << combination << endl;
//    }
//    else
//    {
//        for(int i = index; i < protienList.length(); ++i)
//        {
//            combination.push_back(protienList[i]);
//            permute2(i+1, length);
//            combination.pop_back();
//        }
//    }
//}

int main()
{
    permute();
    cout << endl << count;

    return 0;
}
