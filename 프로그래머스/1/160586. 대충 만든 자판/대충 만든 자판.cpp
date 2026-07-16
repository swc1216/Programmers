#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) 
{
    map<char, int> keyMapping;

    for (string key : keymap)
    {
        for (int i = 0; i < key.size(); i++)
        {
            char alphabat = key[i];
            int index = i + 1;

            auto iter = keyMapping.find(alphabat);
            if (iter != keyMapping.end())
            {
                if (iter->second > index)
                    iter->second = index;
            }
            else
            {
                keyMapping.emplace(key[i], index);
            }
        }
    }

    vector<int> answer;

    for (string target : targets)
    {
        bool isValid = true;
        int count = 0;

        for (int i = 0; i < target.size(); i++)
        {
            char alphabat = target[i];

            auto iter = keyMapping.find(alphabat);

            if (iter != keyMapping.end())
                count += iter->second;
            else
            {
                answer.push_back(-1);
                isValid = false;
                break;
            }
        }

        if(isValid)
            answer.push_back(count);
    }

    return answer;
}