#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int str = 0;
    for(auto ch : s)
    {
        if(ch == '(')
            str++;
        else if(ch == ')')
            str--;
        
        if(str < 0)
            return false;
    }
    
    if(str != 0)
        return false;
    
    return true;
}