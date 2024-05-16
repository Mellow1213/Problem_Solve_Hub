#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string text;
    cin >> text;
    
    vector<string> minus_split;
    stringstream ss(text);
    string temp;

    // '-'를 기준으로 문자열을 나누기
    while (getline(ss, temp, '-')) {
        minus_split.push_back(temp);
    }

    int result = 0;

    // 첫 번째 부분 문자열은 무조건 더해줌
    for (int i = 0; i < minus_split.size(); ++i) {
        int sum = 0;
        stringstream plus_ss(minus_split[i]);
        string plus_temp;

        // '+'를 기준으로 부분 문자열을 나누고 더하기
        while (getline(plus_ss, plus_temp, '+')) {
            sum += stoi(plus_temp);
        }

        if (i == 0) {
            result += sum; // 첫 번째 값은 더하기
        } else {
            result -= sum; // 나머지 값은 빼기
        }
    }

    cout << result << endl;

    return 0;
}
