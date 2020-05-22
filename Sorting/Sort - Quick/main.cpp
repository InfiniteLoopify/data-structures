/* 
 * Created on October 30, 2018, 6:02 PM */
#include <iostream>
#include <ctime>
using namespace std;

void quickSort(int *arr, int left, int right);
int partition(int *arr, int left, int right);
int median(int *arr, int left, int right);
void swap(int &a, int &b);
void display(int *arr, int size);


int main()
{
    int arr[] = {2,4,7,1,9,7,6,8,1,0,4,5,7,2,5,6,8,2,1,0,9};
    int size = sizeof(arr) / sizeof(arr[0]);

    display(arr, size);
    quickSort(arr, 0, size - 1);
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

void quickSort(int *arr, int left, int right)
{
    if(left < right)
    {
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }

}
int partition(int *arr, int left, int right)
{
    int mid = median(arr, left, right);
    swap(arr[mid], arr[right]);
    int pivot = arr[right];

    int i = left - 1;
    for(int j = left; j < right; ++j)
    {
        if(arr[j] <= pivot)
        {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[right], arr[i + 1]);
    return (i + 1);
}

void swap(int &a, int &b)
{
    if(a == b)
        return;

    int temp = a;
    a = b;
    b = temp;
}

int median(int *arr, int left, int right)
{
    int mid = left + (right - left) / 2;
    if(arr[left] > arr[mid])
        swap(arr[left], arr[left]);
    if(arr[left] > arr[right])
        swap(arr[left], arr[right]);
    if(arr[mid] > arr[right])
        swap(arr[mid], arr[right]);
    return mid;
}
