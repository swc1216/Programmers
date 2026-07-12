#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) 
{
    vector<vector<int>> copySizes = sizes;
    vector<int> size(2, 0);

    int answer = 0;

    for (vector<int> rectangle : copySizes)
    {
        sort(rectangle.begin(), rectangle.end());

        size[0] = max(size[0], rectangle[0]);
        size[1] = max(size[1], rectangle[1]);
    }

    answer = size[0] * size[1];

    return answer;
}