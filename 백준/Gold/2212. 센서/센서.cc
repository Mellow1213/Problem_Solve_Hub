#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void SetFastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return;
}

class Highway{
    private:
        int sensor, concent;
        vector<int> vec;
        vector<int> distance;
        int answer = 0;
        void SortVector(){ sort(vec.begin(), vec.end()); }
        void SetDistance()
        { 
            for(int i = 1; i < vec.size(); i++) 
                distance.push_back(vec[i] - vec[i-1]);
        }
    public:
        void SetFieldByIStream();
        void ConcentDistSum();
        void PrintAnswer(){ cout << answer; }
};

void Highway::SetFieldByIStream(){
    int N, K;
    cin >> N >> K;
    
    sensor = N;
    concent = K;
    
    vec.resize(N);
    for(int i = 0; i < N; i++){ cin >> vec[i]; }
    SortVector();
    SetDistance();
}

void Highway::ConcentDistSum(){
    // If the number of concentrators is greater than or equal to the number of sensors
    if (concent >= sensor) {
        answer = 0;
        return;
    }

    sort(distance.begin(), distance.end());
    for(int i = 0; i < sensor - concent; i++){
        answer += distance[i];
    }
}

int main()
{
    Highway highway;
    
    SetFastIO();
    highway.SetFieldByIStream();
    highway.ConcentDistSum();
    highway.PrintAnswer();
    
    return 0;
}
