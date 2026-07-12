#include <string>
#include <vector>

using namespace std;

string solution(string s, int n)
{
    string answer = "";

    for (auto c : s)
    {
        if (c == ' ')
        {
            answer += " ";
            continue;
        }

        int temp = c + n;

        if (c >= 'a' && c <= 'z')
        {
            if (temp > 'z')
                temp -= 26;
        }
        else if (c >= 'A' && c <= 'Z')
        {
            if (temp > 'Z')
                temp -= 26;
        }

        answer += temp;
    }

    return answer;
}