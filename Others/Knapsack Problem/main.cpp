#include <iostream>
#include <vector>
using namespace std;

vector<int> vec;

bool vectorFind(int data)
{
    for(int i = 0; i < vec.size(); ++i)
        if(vec[i] == data)
            return true;
    return false;
}
int vectorSum()
{
    int sum = 0;
    for(int i = 0; i < vec.size(); ++i)
        sum += vec[i];
    return sum;
}
int vectorDisplay()
{
    for(int i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";
    cout << endl;
}
int knapsack(int arr[], int index, int size, int target)
{
    if(vectorSum() == target)
    {
        vectorDisplay();
    }
    else
    {
        for(int i = index; i < size; ++i)
        {
            if(!vectorFind(arr[i]))
            {
                vec.push_back(arr[i]);
                knapsack(arr, index + 1, size, target);
                vec.pop_back();
            }
        }
    }
}

int main()
{
    int target = 19;
    int arr[] = {11, 8, 7, 6, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    knapsack(arr, 0, size, target);
    return 0;
}
