#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int testCase;
    cin >> testCase;
    
    while(testCase--){
        string command;
        string inputString;
        int arrCnt;
        bool isError = false;
        bool reverse = false;
        deque<int> dq;
        
        cin >> command;
        cin >> arrCnt;
        cin >> inputString;
        
        string cache;
        for(const char& p : inputString){
            if(!isdigit(p)){
                if(cache != ""){
                    dq.push_back(stoi(cache));
                    cache = "";
                }
            }
            else{
                cache += p;
            }
        }
        
        for(const char& p : command){
            if(p == 'R'){
                reverse = !reverse;
            }
            else if(p == 'D'){
                if(dq.empty()){
                    isError = true;
                    break;
                }
                
                if(reverse)
                    dq.pop_back();
                else
                    dq.pop_front();
            }
        }
        
        if(isError){
            cout << "error\n";
            continue;
        }
        
        if(dq.empty()){
            cout << "[]\n";
            continue;
        }
        
        cout << '[';
        if(!reverse){
            cout << dq[0];
            for(int i=1; i<dq.size(); i++)
                cout << ',' << dq[i];
        }
        else{
            cout << dq[dq.size()-1];
            for(int i=dq.size()-2; i>=0; i--)
                cout << ',' << dq[i];
        }
        cout << "]\n";
    }
}