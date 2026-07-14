#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int ConvertDay(const string& dateString, int addMonth = 0)
{
    int year = stoi(dateString.substr(0, 4));
    int month = stoi(dateString.substr(5, 2));
    int day = stoi(dateString.substr(8, 2));

    return (year * 12 * 28) + ((month + addMonth - 1) * 28) + (day - 1);
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) 
{
    int iToday = ConvertDay(today);

    unordered_map<string, int> setting;

    for (string term : terms)
    {
        string alpha = term.substr(0, 1);
        int date = stoi(term.substr(2));
        setting.emplace(alpha, date);
    }

    vector<int> answer;

    for (int i = 0; i < privacies.size(); i++)
    {
        string sDay = privacies[i].substr(0, 10);
        string set = privacies[i].substr(11);
        int month = setting.at(set);
        int iDay = ConvertDay(sDay, month);
        if (iToday >= iDay)
            answer.push_back(i + 1);
    }

    return answer;
}