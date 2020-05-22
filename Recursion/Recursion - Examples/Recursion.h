/* Created on September 19, 2018, 9:22 PM */
#ifndef RECURSION_H
#define RECURSION_H

int ackerman(int m, int n);
int mult(int a, int b, int ans);
int mult(int a, int b);
int count(int *arr, int size, int find, int counter);
int count(int *arr, int size, int find);
int smallestNum(int *arr, int size, int small = 0);
int squareRoot(int num, int temp);
void towerOfHanoi(int n, char from_rod, char aux_rod, char to_rod);
int selectSort(int arr[], int size, int index = 0);
int bubbleSort(int arr[], int size, int index = 0);
void starPrint(int n);


#endif /* RECURSION_H */
