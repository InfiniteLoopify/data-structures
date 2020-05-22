/*
 * Created on November 2, 2018, 6:25 PM */
#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int find)
{
    int start = 0;
    int end = size - 1;
    int middle = 0;
    
    while(true)
    {
        middle = (start + end) / 2;
        
        if(arr[middle] == find)
            return middle;
        else if(start > end)
            return -1;
        
        else if(arr[middle] < find)
            start = middle + 1;
        else if(arr[middle] > find)
            end = middle - 1; 
    }
}

int main()
{
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i = -1; i <= size; ++i)
        cout << binarySearch(arr, size, i) << " ";  
    return 0;
}

