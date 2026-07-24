#include <string>
#include <vector>

using namespace std;

string solution(string s) 
{
    string answer = "";

    bool isFirstAlpha = true;
    for (const auto& c : s)
    {
        if (c == ' ')
        {
            answer += c;
            isFirstAlpha = true;
            continue;
        }
        else if (isalpha(c) && isFirstAlpha)
        {
            answer += toupper(c);
        }
        else if(isalpha(c))
        {
            answer += tolower(c);
        }
        else
        {
            answer += c;
        }

        isFirstAlpha = false;
    }

    return answer;
}