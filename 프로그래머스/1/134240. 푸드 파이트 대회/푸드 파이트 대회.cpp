#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> food)
{
    string answer = "";

    string indexString;
    for (int i = 1; i < food.size(); i++)
    {
        int count = food[i];
        if (count < 2)
            continue;

        int forSize = count / 2;
        for(int j = 0; j < forSize; j++)
            indexString += to_string(i);
    }

    answer = indexString + "0";
    reverse(indexString.begin(), indexString.end());
    answer += indexString;

    return answer;
}