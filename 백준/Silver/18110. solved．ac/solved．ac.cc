#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int CalcDifficulty(int opinionNum){
    if(opinionNum == 0){
        return 0;
    }
    
    vector<float> vec(opinionNum);
    float average = 0;
    
    int startRange = round(opinionNum * 0.15f);
    int endRange = opinionNum - startRange;
    
    for(int i=0; i<opinionNum; i++){
        int temp;
        cin >> temp;
        vec[i] = temp;
    }
    
    sort(vec.begin(), vec.end());
    
    for(int i=startRange; i<endRange; i++){
        average += vec[i];
    }
    return round(average / (endRange - startRange));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int opinionNum;
    
    cin >> opinionNum;
    
    cout << CalcDifficulty(opinionNum);
}