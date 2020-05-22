#include <iostream>
#include <string>
#include "Stack.h"

bool delimiter(const std::string &str)
{
    Stack <char> st;
    for(int i = 0; i < str.length(); ++i)
    {
        if(str[i] == '[' || str[i] == '(' || str[i] == '{')
            st.push(str[i]);
        else if(str[i] == ']' || str[i] == ')' || str[i] == '}')
        {
            char ch = st.peek();
            if(ch == -1)
                return false;
            else if(ch == '[' && str[i] == ']')
                st.pop();
            else if(ch == '(' && str[i] == ')')
                st.pop();
            else if(ch == '{' && str[i] == '}')
                st.pop();
            else
                return false;
        }
    }
    if(st.isEmpty())
        return true;
    else
        return false;
}

int main()
{
    std::cout << delimiter("()");
    return 0;
}
