#include <iostream>
#include <vector>
using namespace std;

string str;
int tc;

void Solve() {
    int counter = 0;
    int start, end;
    char ch;
    cin >> ch >> start >> end;
    for(int i=start; i<=end; i++) {
        if(str[i] == ch)
            counter++;
    }
    cout << counter << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> str >> tc;
    
    for(int i=0; i<tc; i++) {
        Solve();
    }
}