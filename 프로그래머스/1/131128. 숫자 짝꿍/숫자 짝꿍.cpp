#include <string>
#include <algorithm>

using namespace std;

string solution(string X, string Y)
{
    int xCount[10] = {};
    int yCount[10] = {};

    for (char ch : X)
        xCount[ch - '0']++;

    for (char ch : Y)
        yCount[ch - '0']++;

    string answer;

    string copyX = X;
    string copyY = Y;

    for (int number = 9; number >= 0; number--)
    {
        int commonCount = min(xCount[number], yCount[number]);

        answer.append(commonCount, static_cast<char>('0' + number));
    }

    if (answer.empty())
        return "-1";

    if (answer[0] == '0')
        return "0";

    return answer;
}