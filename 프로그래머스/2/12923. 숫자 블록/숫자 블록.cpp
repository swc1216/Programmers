#include <string>
#include <vector>

using namespace std;

int GetBlockNumber(long long blockIndex)
{
    if (blockIndex == 1)
        return 0;

    int BlockNumber = 1;

    for (long long i = 2; i * i <= blockIndex; i++)
    {
        if (blockIndex % i != 0)
            continue;

        long long div = blockIndex / i;

        if (div <= 10'000'000)
            return static_cast<int>(div);

        BlockNumber = static_cast<int>(i);
    }

    return BlockNumber;
}

vector<int> solution(long long begin, long long end)
{
    vector<int> answer;

    for (long long i = begin; i <= end; i++)
    {
        answer.push_back(GetBlockNumber(i));
    }

    return answer;
}