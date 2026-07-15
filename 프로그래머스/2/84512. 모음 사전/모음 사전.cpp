#include <string>
#include <vector>
#include <cmath>

using namespace std;

using namespace std;

int solution(string word) 
{   
    const int maxWordSize = 5;
    int answer = 0;

    int wordSize = word.size();
    vector<int> numWord(wordSize, 0);

    for(int i = 0; i < wordSize; i++)
    {
        if (word[i] == 'A')
            numWord[i] = 0;
        else if (word[i] == 'E')
            numWord[i] = 1;
        else if (word[i] == 'I')
            numWord[i] = 2;
        else if (word[i] == 'O')
            numWord[i] = 3;
        else if (word[i] == 'U')
            numWord[i] = 4;
    }

    for (int i = 0; i < wordSize; i++)
    {
        answer += pow(5, (maxWordSize - 1 - i)) * numWord[i] + 1;
    }

    for (int i = 0; i < wordSize; i++)
    {
        int prevNum = numWord[i];

        for (int j = 0; j < maxWordSize - i - 1; j++)
        {
            answer += pow(5, j) * prevNum;
        }
    }

    if (wordSize < 5)
    {
        int prevNum = numWord[wordSize - 1];

        numWord[wordSize] = prevNum;

        for (int i = 1; i + wordSize < 5; i++)
        {
            numWord[wordSize + i] = pow(5, i) * prevNum;
        }
    }

    return answer;
}