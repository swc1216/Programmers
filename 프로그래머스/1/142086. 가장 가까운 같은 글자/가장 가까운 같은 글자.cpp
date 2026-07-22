#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) 
{
    vector<int> answer;

    map<char, int> charIndex;

    for (int i = 0; i < s.size(); i++)
    {
        char alpha = s[i];

        auto iter = charIndex.find(alpha);
        if (iter != charIndex.end())
        {
            int alphaIndex = iter->second;
            answer.push_back(i - alphaIndex);
            iter->second = i;
        }
        else
        {
            charIndex.emplace(alpha, i);
            answer.push_back(-1);
        }
    }

    return answer;
}