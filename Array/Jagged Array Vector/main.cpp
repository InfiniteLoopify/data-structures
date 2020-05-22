/* 
 * File:   main.cpp
 *
 * Created on September 15, 2018, 11:35 PM
 */
#include <cstdlib>

using namespace std;

int main()
{
    vector <vector <int> > jagged;
    for(int i = 0; i < 10 ; ++i)
        jagged.push_back(vector <int> ());
    
    cout << "Total Numbers: ";
    int number = 0;
    cin >> number;
    cout << "\n";
    
    for(int i = 0; i < number; ++i)
    {
        int temp = 0;
        cout << "Number " << i << ": ";
        cin >> temp;
        jagged[temp % 10].push_back(temp);
    }
    for(int i = 0; i < 10 ; ++i)
    {
        for(int j = 0; j < jagged[i].size(); ++j)
            cout << jagged[i][j] << " ";
        cout << endl;
    }
    return 0;
}

