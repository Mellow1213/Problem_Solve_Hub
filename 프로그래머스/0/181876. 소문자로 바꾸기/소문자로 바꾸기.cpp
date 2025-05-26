#include <string>
#include <vector>
#define VAR_UPPER 32
using namespace std;

string solution(string myString) {
    int newSize = myString.size();
    string answer = "";
    answer.reserve(newSize);
    for(const auto& p : myString) {
        char curChar = (p >= 'A' && p <= 'Z' ? p+VAR_UPPER : p);
        answer.push_back(curChar);
    }
    return answer;
}