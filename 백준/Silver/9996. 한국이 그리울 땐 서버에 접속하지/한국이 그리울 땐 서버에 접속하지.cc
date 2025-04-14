#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string str, char Delimiter) {
    istringstream iss(str);             // istringstream에 str을 담는다.
    string buffer;                      // 구분자를 기준으로 절삭된 문자열이 담겨지는 버퍼
 
    vector<string> result;
 
    // istringstream은 istream을 상속받으므로 getline을 사용할 수 있다.
    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);               // 절삭된 문자열을 vector에 저장
    }
 
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    vector<string> arr(N);
    string pattern;
    cin >> pattern;
    vector<string> ptn = split(pattern, '*');
    bool flag = true;
    for(int i=0; i<N; i++) {
        cin >> arr[i];
        string& word = arr[i];
        flag = true;
        
        if(word.size() < ptn[0].size() + ptn[1].size()){
            cout << "NE\n";
            continue;
        }
        
        for(int j=0; j<ptn[0].size(); j++) {
            if(word[j] != ptn[0][j]) {
                flag = false;
                break;
                // 패턴 아님
            }
        }
        
        if(flag) {
            for(int j=0; j<ptn[1].size(); j++) {
                if(word[word.size() - ptn[1].size() + j] != ptn[1][j]) {
                    flag = false;
                    break;
                }
            }
        }
        
        cout << (flag ? "DA\n" : "NE\n");
    }
}
