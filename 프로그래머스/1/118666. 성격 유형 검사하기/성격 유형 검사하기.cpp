#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) 
{
    // R - T
    // C - F
    // J - M
    // A - N
    string answer = "";

    vector<int> kakaoMBTI = { 0, 0, 0, 0 };

    int forSize = survey.size();
    for (int i = 0; i < forSize; i++)
    {
        int score = choices[i] - 4;
        if (score == 0)
            continue;

        int reverse = 1;
        string type = survey[i];
        if (type[0] > type[1])
            reverse = -1;

        if (type == "RT" || type == "TR")
            kakaoMBTI[0] += reverse * score;
        else if (type == "CF" || type == "FC")
            kakaoMBTI[1] += reverse * score;
        else if (type == "JM" || type == "MJ")
            kakaoMBTI[2] += reverse * score;
        else if (type == "AN" || type == "NA")
            kakaoMBTI[3] += reverse * score;
    }

    if (kakaoMBTI[0] <= 0)
        answer += "R";
    else
        answer += "T";

    if (kakaoMBTI[1] <= 0)
        answer += "C";
    else
        answer += "F";

    if (kakaoMBTI[2] <= 0)
        answer += "J";
    else
        answer += "M";

    if (kakaoMBTI[3] <= 0)
        answer += "A";
    else
        answer += "N";


    return answer;
}