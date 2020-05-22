/* 
 * Created on October 30, 2018, 6:02 PM */
#include <iostream>
using namespace std;

void heapify(int *arr, int size, int i);
void heapSort(int *arr, int size);
void swap(int &a, int &b);
void display(int *arr, int size);

int main()
{
    int arr[] = {3,6,9,1,5,8,2,0,10,20,70,40};
    int size = sizeof(arr) / sizeof(arr[0]);

    display(arr, size);
    heapSort(arr, size);
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

void heapify(int *arr, int size, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && arr[left] > arr[largest])
        largest = left;
    if(right < size && arr[right] > arr[largest])
        largest = right;

    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }
}
void heapSort(int *arr, int size)
{
    for(int i = size / 2 - 1; i >= 0; --i)
        heapify(arr, size, i);

    for(int i = size - 1; i >= 0; --i)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void swap(int &a, int &b)
{
    if(a == b)
        return;

    int temp = a;
    a = b;
    b = temp;
}
