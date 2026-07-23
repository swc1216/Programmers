#include<vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    vector<int> copyA = A;
    vector<int> copyB = B;
    
    sort(copyA.begin(), copyA.end());
    sort(copyB.begin(), copyB.end(), greater<int>());
    
    for(int i = 0; i < copyA.size(); i++)
    {
        answer += copyA[i] * copyB[i];
    }

    return answer;
}