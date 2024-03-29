#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    
    cin >> N;
    
    string name[N];
    int age[N];
    
    vector<int> haveAge;
    
    for(int i=0; i<N; i++){
        cin >> age[i] >> name[i];
        
        if(haveAge.empty()) {
            haveAge.push_back(age[i]);
            
        }
        else{
            bool flag = false;
            int j;
            for(j=0; j<haveAge.size(); j++){
                if(age[i] == haveAge[j]){
                    flag = true;
                }
            }
            if(!flag) 
                haveAge.push_back(age[i]);
        }
        
    }
    
    for(int i=0; i<haveAge.size(); i++){
        for(int j=i; j<haveAge.size(); j++){
            if(haveAge[i] > haveAge[j]){
                int temp = haveAge[i];
                haveAge[i] = haveAge[j];
                haveAge[j] = temp;
            }
        }
    }
    
    for(int i=0; i<haveAge.size(); i++){
        for(int j=0; j<N; j++){
            if(age[j] == haveAge[i]){
                cout << age[j] << " " << name[j] << '\n';
            }
        }
    }
}