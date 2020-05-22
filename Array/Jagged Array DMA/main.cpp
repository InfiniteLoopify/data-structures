#include <iostream>
#include "Jagged.h"

int main()
{
    Jagged arr;
    
    std::cout << "Total Numbers: ";
    int number = 0;
    std::cin >> number;
    std::cout << "\n";
    
    for(int i = 0; i < number; ++i)
    {
        int temp = 0;
        std::cout << "Number " << i << ": ";
        std::cin >> temp;
        arr.insert(temp, temp % 10);
    }
    arr.display();
    return 0;
}
