#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) 
{
    int answer = 0;
    
    unordered_map<int, int> fruits;
    for (int size : tangerine)
        fruits[size]++;

    vector<int> fruitCounts;
    for (const auto& fruit : fruits)
        fruitCounts.push_back(fruit.second);

    int copyK = k;

    sort(fruitCounts.begin(), fruitCounts.end(), greater<int>());
    for (int i = 0; i < fruitCounts.size(); i++)
    {
        copyK -= fruitCounts[i];

        if (copyK <= 0)
        {
            answer = i + 1;
            break;
        }
    }

    return answer;
}