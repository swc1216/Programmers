#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) 
{
    string answer = "";

    for (string str : goal)
    {
        string card1 = cards1.front();
        if (str == card1)
        {
            cards1.erase(cards1.begin());
            continue;
        }

        string card2 = cards2.front();
        if (str == card2)
        {
            cards2.erase(cards2.begin());
            continue;
        }

        return "No";
    }

    return "Yes";
}