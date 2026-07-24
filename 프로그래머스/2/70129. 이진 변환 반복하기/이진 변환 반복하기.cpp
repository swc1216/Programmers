#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string ConvertBinary(int length)
{
    std::string binary = "";

    while (length > 0)
    {
        binary += std::to_string(length % 2);
        length /= 2;
    }

    std::reverse(binary.begin(), binary.end());

    return binary;
}

vector<int> solution(string s)
{
    int convertCount = 0;
    int removedZeroCount = 0;

    while (s != "1")
    {
        int zeroCount = std::count(s.begin(), s.end(), '0');

        removedZeroCount += zeroCount;

        int oneCount = static_cast<int>(s.size()) - zeroCount;

        s = ConvertBinary(oneCount);
        convertCount++;
    }

    return { convertCount, removedZeroCount };
}