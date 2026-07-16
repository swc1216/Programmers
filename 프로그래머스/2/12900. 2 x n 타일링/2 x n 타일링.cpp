#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    constexpr long long MOD = 1000000007;

    if (n <= 1)
        return 1;

    long long prev2 = 1;
    long long prev1 = 1;

    for (int i = 2; i <= n; ++i)
    {
        long long current = (prev1 + prev2) % MOD;

        prev2 = prev1;
        prev1 = current;
    }

    return static_cast<int>(prev1);
}