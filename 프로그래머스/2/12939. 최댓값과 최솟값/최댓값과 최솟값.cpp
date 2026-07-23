#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) 
{
    istringstream ss (s);
    string temp;
    vector<int> number;
    
    while(getline(ss,temp,' '))
        number.push_back(stoi(temp));
    
    sort(number.begin(), number.end());
    
    string answer = "";
    
    answer += to_string(number[0]);
    answer += " ";
    answer += to_string(number[number.size() - 1]);
    
    return answer;
}