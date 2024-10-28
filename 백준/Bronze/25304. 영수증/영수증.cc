#include <iostream>
using namespace std;

int main(){
    int cost, stuff;
    cin >> cost >> stuff;
    
    for(int i=0; i<stuff; i++){
        int temp1, temp2;
        cin >> temp1 >> temp2;
        cost -= temp1*temp2;
    }
    
    cout << (cost == 0 ? "Yes" : "No");
}