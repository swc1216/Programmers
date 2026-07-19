#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) 
{
    map<string, int> score;
    for (int i = 0; i < name.size(); i++)
        score.emplace(name[i], yearning[i]);

    vector<int> answer;

    for (int i = 0; i < photo.size(); i++)
    {
        int count = 0;
        vector<string> photoPerson = photo[i];

        for (int j = 0; j < photoPerson.size(); j++)
        {
            auto iter = score.find(photoPerson[j]);
            if (iter != score.end())
                count += iter->second;
        }

        answer.push_back(count);
    }

    return answer;
}