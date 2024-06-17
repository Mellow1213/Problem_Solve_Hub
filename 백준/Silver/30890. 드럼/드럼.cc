#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int X, Y;
    
    cin >> X >> Y;
    
    vector<int> vec;
    
    for(int i=1;i<X*Y+1; i++){
        if(i%X==0 && i%Y==0){
            vec.push_back(3);
        }
        else if(i%X==0){
            vec.push_back(2);
        }
        else if(i%Y==0){
            vec.push_back(1);
        }
    }
    
    for(int i=0; i<vec.size(); i++){
        cout << vec[i];
    }
}
