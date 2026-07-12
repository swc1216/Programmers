#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) 
{
    int answer = 0;

    int totalBottle = n;
    while (totalBottle >= a)
    {
        int divideBottle = (totalBottle / a);
        int returnBottle = divideBottle * b;
        answer += returnBottle;
        totalBottle = totalBottle - (divideBottle * a) + returnBottle;
    }

    return answer;
}