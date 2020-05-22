#include <iostream>
#include <string>
#include "Stack.h"

int main()
{
    Stack<char, 20> st;
    std::string str1 = "Abcde";

    for(int i = 0; i < str1.length(); ++i)
        st.push(str1[i]);
    std::cout << str1 << "\n";

    for(int i = 0; i < str1.length(); ++i)
        str1[i] = st.pop();
    std::cout << str1 << "\n";

    return 0;
}
