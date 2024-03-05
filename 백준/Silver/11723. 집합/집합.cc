#include <iostream>
#include <string>
#include <bitset>
using namespace std;

class Test{
private:
    bitset<21> S; // 1부터 20까지의 값을 저장하기 위해 bitset을 사용합니다.
public:
    void Add(int num);
    void Remove(int num);
    void Check(int num);
    void Toggle(int num);
    void All();
    void Empty();
};

void Test::Add(int num){
    S.set(num, true); // num에 해당하는 비트를 true로 설정합니다.
}

void Test::Remove(int num){
    S.set(num, false); // num에 해당하는 비트를 false로 설정합니다.
}
void Test::Check(int num){
    cout << S.test(num) << '\n'; // num에 해당하는 비트가 true이면 1, 아니면 0을 출력합니다.
}
void Test::Toggle(int num){
    S.flip(num); // num에 해당하는 비트의 값을 반전시킵니다.
}
void Test::All(){
    S.set(); // 모든 비트를 true로 설정합니다.
}
void Test::Empty(){
    S.reset(); // 모든 비트를 false로 설정합니다.
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int M;
    string command;
    int commandNum;
    
    Test t;
    
    cin >> M;
    
    for(int i = 0; i < M; i++){
        cin >> command;
        if (command != "all" && command != "empty")
            cin >> commandNum;
        
        if(command == "add")
            t.Add(commandNum);
        else if(command == "check")
            t.Check(commandNum);
        else if(command == "remove")
            t.Remove(commandNum);
        else if(command == "toggle")
            t.Toggle(commandNum);
        else if(command == "all")
            t.All();
        else if(command == "empty")
            t.Empty();
    }
    return 0;
}
