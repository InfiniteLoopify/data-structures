#include <iostream>

using namespace std;

void combSort(int *arr, int size);
void display(int *arr, int size);


int main()
{
    int arr[] = {3,8,6,1,9,7,5,3,5,7,0,8,5,1,2,7,9,0,6,4,3,8};
    int size = sizeof(arr) / sizeof(arr[0]);

    display(arr, size);
    combSort(arr, size);
    display(arr, size);

    return 0;
}

void sort(int *arr, int size)
{
    int gap = size;
    while(gap != 1)
    {
        bool swapped = false;

        gap /= 1.3;
        if(gap < 1)
            gap = 1;

        int i = 0;
        while(i + gap < size)
        {
            if(arr[i] > arr[i + gap])
            {
                swapped = true;
                int temp = arr[i];
                arr[i] = arr[i + gap];
                arr[i + gap] = temp;
            }
            ++i;
        }
        if(!swapped)
            return;
    }
}
void display(int *arr, int size)
{
    for(int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
