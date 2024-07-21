#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<vector<char>> blackboard(5, vector<char>(15, '.'));
    int max_width = 0;

    // 입력 받기
    for(int i = 0; i < 5; i++){
        string temp;
        cin >> temp;
        for(int j = 0; j < temp.size(); j++){
            blackboard[i][j] = temp[j];
        }
        max_width = max(max_width, (int)temp.size());
    }
    
    // 세로로 읽기
    for(int j = 0; j < max_width; j++){
        for(int i = 0; i < 5; i++){
            if(blackboard[i][j] != '.'){
                cout << blackboard[i][j];
            }
        }
    }
    
    cout << endl;
    
    return 0;
}