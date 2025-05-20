#include <iostream>
#include <vector>
using namespace std;

int min(int a, int b) {
    return (a<b ? a : b);
}

void ChangeLight(vector<bool>& origin, int switchNum) {
    if(switchNum == 0) {
        for(int i=0; i<=1; i++) {
            origin[switchNum+i] = !origin[switchNum+i];
        }
    } else if( switchNum == origin.size()-1 ) {
        for(int i=-1; i<=0; i++) {
            origin[switchNum+i] = !origin[switchNum+i];
        }
    } else {
        for(int i=-1; i<=1; i++) {
            origin[switchNum+i] = !origin[switchNum+i];
        }
    }
    
}

int GetChangeCount(vector<bool>& origin, const vector<bool>& target) {
    int answer = 0;
    int n = origin.size();
    for(int i=0; i<n-1; i++) {
        if(origin[i] != target[i]) {
            ChangeLight(origin, i+1);
            answer++;
        }
    }
    
    return (origin == target ? answer : -1);
}

int main()
{
    int n;
    cin >> n;
    vector<bool> bulbs(n);
    vector<bool> target(n);
    string s;
    cin >> s;
    for(int i=0; i<n; i++) {
        bulbs[i] = (s[i]=='1');
    }
    
    cin >> s;
    for(int i=0; i<n; i++) {
        target[i] = (s[i]=='1');
    }
    vector<bool> bulbs2 = bulbs;
    int res1 = GetChangeCount(bulbs, target);
    ChangeLight(bulbs2, 0);
    int res2 = GetChangeCount(bulbs2, target);
    if(res2 != -1) res2++;
    
    if(res1 == -1 && res2 == -1) {
        cout << -1;
    } else if( res1 == -1) {
        cout << res2;
    } else if (res2 == -1) {
        cout << res1;
    } else {
        cout << min(res1, res2);
    }
}