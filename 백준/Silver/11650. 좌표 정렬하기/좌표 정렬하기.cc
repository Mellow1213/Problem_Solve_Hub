#include <iostream>
#include <set>
using namespace std;

struct Position {
    
    int x;
    int y;
    
    bool operator < (const Position &var) const{
        if(x != var.x)
            return x<var.x;
        else
            return y<var.y;
    }
    
};

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    set<Position> s;
    int trial;
    
    cin >> trial;
    
    for(int i=0; i<trial; i++){
        int tempX, tempY;
        cin >> tempX >> tempY;
        s.insert({tempX, tempY});
    }
    
    for(auto it = s.begin(); it != s.end(); it++){
        cout << it->x << ' ' << it->y << '\n';
    }
}
