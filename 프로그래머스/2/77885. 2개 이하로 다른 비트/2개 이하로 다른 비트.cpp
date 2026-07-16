#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;
    answer.reserve(numbers.size());

    for (auto num : numbers)
    {
        // 짝수 일 때
        if ((num & 1) == 0)
        {
            answer.push_back(num + 1);
        }
        // 홀수 일 때
        else
        {
            long long temp = (num ^ (num + 1)) >> 2;
            temp = num + 1 + temp;
            answer.push_back(temp);
        }
    }
    
    return answer;
}