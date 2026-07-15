#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <utility>

using namespace std;

vector<string> solution(vector<string> record) 
{
    vector<string> answer;

    unordered_map<string, string> users;
    vector<pair<string, string>> log;

    for (int i = 0; i < record.size(); i++)
    {
        vector<string> words;

        istringstream ss(record[i]);
        string temp;

        while (getline(ss, temp, ' ')) 
            words.push_back(temp);

        if (words[0] == "Enter")
        {
            auto iter = users.find(words[1]);

            if (iter != users.end())
                iter->second = words[2];
            else
                users.emplace(words[1], words[2]);

            log.push_back({ words[0], words[1] });
        }
        else if (words[0] == "Leave")
            log.push_back({ words[0], words[1] });
        else if (words[0] == "Change")
        {
            auto iter = users.find(words[1]);

            if (iter != users.end())
                iter->second = words[2];
        }
    }

    for (const auto& pair : log)
    {
        string sentence;

        string log = pair.first;
        string userID = pair.second;

        string userName;
        auto iter = users.find(userID);
        if (iter != users.end())
            userName = iter->second;

        if (log == "Enter")
            sentence = userName + "님이 들어왔습니다.";
        else if(log == "Leave")
            sentence = userName + "님이 나갔습니다.";

        answer.push_back(sentence);
    }

    return answer;
}