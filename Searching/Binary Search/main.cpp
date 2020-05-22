#include <iostream>
using namespace std;

int binarySearch(int arr[], int start, int end, int value);
int binarySearch(int arr[], int start, int end, int value, int &leftI, int &rightI);
void display(int arr[], int size);

int main()
{
    int arr[] = {1,1,1,1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr) / sizeof(arr[0]);

    display(arr, size);
    //int left, right;
    cout << binarySearch(arr, 0, size, 1);
    //cout << "\n" << left << " " << right;
    return 0;
}

int binarySearch(int arr[], int start, int end, int value)
{
    while(start <= end)
    {
        int middle = start + (end - start) / 2;
        if(arr[middle] < value)
        {
            start = middle + 1;
        }
        else if(arr[middle] > value)
            end = middle - 1;
        else
            return middle;
    }
    return -1;
}
int binarySearch(int arr[], int start, int end, int value, int &leftI, int &rightI)
{
    while(start <= end)
    {
        int middle = start + (end - start) / 2;
        if(arr[middle] < value)
        {
            start = middle + 1;
        }
        else if(arr[middle] > value)
            end = middle - 1;
        else
        {
            leftI = rightI = middle;
            while(arr[leftI] == value)
                --leftI;
            while(arr[rightI] == value)
                ++rightI;
            ++leftI; --rightI;
            return middle;
        }
    }
    leftI = rightI = -1;
    return -1;

}
void display(int arr[], int size)
{
    for(int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
