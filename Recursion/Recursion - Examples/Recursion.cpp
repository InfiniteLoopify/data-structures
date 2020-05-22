/* Created on September 19, 2018, 9:22 PM */
#include <iostream>
#include "Recursion.h"

//ackerman function
int ackerman(int m, int n)
{
    if(m == 0) return n+1;
    else if(n == 0) return ackerman(m-1, 1);
    else return ackerman(m-1, ackerman(m, n-1));
}

//multiply a*b with +/- operators
int mult(int a, int b, int ans)
{
    if(a == 0)
        return ans;
    
    return mult(a-1, b, b+ans);
}

//multiply a*b with +/- operators
int mult(int a, int b)
{
    if(a == 0)
        return 0;
    
    return b + mult(a-1, b);
}

//finding count of an integer in an array
int count(int *arr, int size, int find, int counter)
{
    if(size == 0)
        return counter;
    
    if(arr[size - 1] == find)
        ++counter;
    
    return count(arr, size - 1, find, counter);
}

//finding count of an integer in an array
int count(int *arr, int size, int find)
{
    if(size == 0)
        return 0;
    
    if(arr[size - 1] == find)
        return 1 + count(arr, size - 1, find);
    
    else
        return 0 + count(arr, size - 1, find);
}

//finding smallest number in array
int smallestNum(int *arr, int size, int small)
{
    if(size == 0)
        return small;
    
    if(arr[size] < small)
        small = arr[size];
    
    return smallestNum(arr, size - 1, small);   
}

int squareRoot(int num, int temp)
{
    if(temp == 0)
        return -1;
    if(temp * temp == num)
        return temp;
    
    return squareRoot(num, temp - 1);
}

//tower of hanoi
void towerOfHanoi(int n, char from_rod, char aux_rod, char to_rod)
{ 
    if (n == 1) 
    { 
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod); 
        return; 
    } 
    towerOfHanoi(n-1, from_rod, to_rod, aux_rod); 
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod); 
    towerOfHanoi(n-1, aux_rod, from_rod, to_rod); 
}

//selection sort
int selectSort(int arr[], int size, int index)
{
    if(index >= size)
        return 0;
    
    int minIndex = index;
    for(int i = index+1; i < size; ++i)
    {
        if(arr[i] < arr[minIndex])
            minIndex = i;
    }
    int temp = arr[index];
    arr[index] = arr[minIndex];
    arr[minIndex] = temp;
    
    selectSort(arr, size, index+1);
}

//bubble sort
int bubbleSort(int arr[], int size, int index)
{
    if(index >= size)
        return 0;
    
    for(int i = 0; i < size; ++i)
    {
        if(arr[i+1] < arr[i])
        {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;    
        }
    }
    bubbleSort(arr, size, index+1);
}

//star print
void starPrint(int n)
{
    int i = 0;  
    if (n > 1)
        starPrint(n-1);
    for (i = 0; i < n; i++)
        printf(" * ");
    printf("\n");
}
