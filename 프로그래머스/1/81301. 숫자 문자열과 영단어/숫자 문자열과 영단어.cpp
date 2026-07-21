#include <string>
#include <vector>

using namespace std;

int solution(string s) 
{
    vector<string> words = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

    int answer = 0;

    for (int i = 0; i < words.size(); i++)
    {
        size_t pos;

        while ((pos = s.find(words[i])) != string::npos)
        {
            s.replace(pos, words[i].length(), to_string(i));
        }
    }

    answer = stoi(s);

    return answer;
}