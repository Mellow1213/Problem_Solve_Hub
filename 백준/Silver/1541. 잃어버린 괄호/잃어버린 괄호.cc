#include <iostream>
#include <cctype>
#include <vector>

using namespace std;

void AddTextByNum(int& result, string str, bool addOption){
    result += addOption ? stoi(str) : -1*stoi(str);
}

int main()
{
    string text;
    int result = 0;
    bool isFirstNum = true;
    cin >> text;
    string temp = "";
    
    for(int i=0; text[i]!=0; i++){
        if(text[i] == '-' || text[i] == '+'){
            if(isFirstNum && text[i] == '+'){
                AddTextByNum(result, temp, isFirstNum);
            }
            else{
                AddTextByNum(result, temp, isFirstNum);
                isFirstNum = false;
            }
            temp.clear();
        }
        else{
            temp+=text[i];
        }
    }
    
    AddTextByNum(result, temp, isFirstNum);
    
    cout << result;
}
