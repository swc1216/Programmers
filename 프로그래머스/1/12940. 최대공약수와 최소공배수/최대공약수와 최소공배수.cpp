#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m)
{
    int originalN = n;
    int originalM = m;

    while (m != 0)
    {
        int remainder = n % m;
        n = m;
        m = remainder;
    }

    int gcd = n;
    int lcm = originalN / gcd * originalM;

    return {gcd, lcm};
}