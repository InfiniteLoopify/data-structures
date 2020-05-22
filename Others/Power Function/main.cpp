#include <iostream>
#include <ctime>
using namespace std;

int pow(int a, int b)
{
    if(b == 0)
        return 1;
    if(b == 1)
        return a;

    return pow(a, b/2) * pow(a, b - b/2);
}

int pow2(int a, int b)
{
    int ans = 1;
    for(int i = 0; i < b; ++i)
        ans *= a;
    return ans;
}

int main()
{
    clock_t tStart1 = clock();
    /* Do your stuff here */
    cout << pow(2, 999999) << "\n";
    printf("Time taken: %.2fs\n", (double)(clock() - tStart1)/CLOCKS_PER_SEC);


    clock_t tStart2 = clock();
    /* Do your stuff here */
    cout << pow2(2, 999999) << "\n";
    printf("Time taken: %.2fs\n", (double)(clock() - tStart2)/CLOCKS_PER_SEC);

    return 0;
}
