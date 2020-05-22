/*
 * Created on October 30, 2018, 6:02 PM */
#include <iostream>
using namespace std;

void sort(int *arr, int size);
void display(int *arr, int size);

int main()
{
    int arr[] = {2,4,7,1,9,7,6,8,1,0,4,5,7,2,5,6,8,2,1,0,9};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    display(arr, size);
    sort(arr, size);
    display(arr, size);
    return 0;
}

void display(int *arr, int size)
{
    for(int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void sort(int *arr, int size)
{
    for(int i = 0; i < size - 1; ++i)
    {
        int min = i;
        for(int j = i + 1; j < size; ++j)
        {
            if(arr[min] > arr[j])
                min = j;
        }
        if(i != min)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
