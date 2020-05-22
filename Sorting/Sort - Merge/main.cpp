/*
 * Created on October 30, 2018, 6:02 PM */
#include <iostream>
using namespace std;

void mergeSort(int *arr, int left, int right);
void merge(int *arr, int left, int middle, int right);
void display(int *arr, int size);

int main()
{
    int arr[] = {2,4,7,1,9,7,6,8,1,0,4,5,7,2,5,6,8,2,1,0,9};
    int size = sizeof(arr) / sizeof(arr[0]);

    display(arr, size);
    mergeSort(arr, 0, size );
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

void mergeSort(int *arr, int left, int right)
{
    if(left < right)
    {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

void merge(int *arr, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for(int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for(int i = 0; i < n2; ++i)
        R[i] = arr[middle + i + 1];

    int i = 0;
    int j = 0;
    int k = left;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            ++i;
        }
        else
        {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    while(i < n1)
    {
        arr[k] = L[i];
        ++i;
        ++k;
    }
    while(j < n2)
    {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}


