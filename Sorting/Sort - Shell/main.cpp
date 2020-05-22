#include <iostream>

using namespace std;

void sort(int *arr, int size);
void display(int *arr, int size);

int main()
{
    int arr[] = {3,8,6,1,9,7,5,3,5,7,0,8,5,1,2,7,9,0,6,4,3,8};
    int size = sizeof(arr) / sizeof(arr[0]);

    display(arr, size);
    sort(arr, size);
    display(arr, size);

    return 0;
}

void sort(int *arr, int size)
{
    for(int gap = size / 2; gap > 0; gap /= 2)
    {
        for(int i = gap; i < size; ++i)
        {
            int key = arr[i];
            int j = i - gap;
            while(j >= 0 && key < arr[j])
            {
                arr[j + gap] = arr[j];
                j -= gap;
            }
            arr[j + gap] = key;
        }
    }
}

void display(int *arr, int size)
{
    for(int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
