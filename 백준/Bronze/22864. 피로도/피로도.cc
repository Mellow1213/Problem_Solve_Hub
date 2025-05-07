#include <iostream>
#include <vector>

using namespace std;

class Worker {
    int workFatigue;
    int workTask;
    int restFatigue;
    int maxFatigue;
    
    int currentTask = 0;
    int currentFatigue = 0;
    
    void Rest() {
        currentFatigue -= restFatigue;
        if(currentFatigue < 0) currentFatigue = 0;
    }
    void Work() {
        currentTask += workTask;
        currentFatigue += workFatigue;
    }
    public:
        Worker(int a, int b, int c, int m) : 
            workFatigue(a), workTask(b), restFatigue(c), maxFatigue(m) { }
        void TryWork() {
            if(currentFatigue + workFatigue > maxFatigue) {
                Rest();
            } else {
                Work();
            }
        }
        int WorkAmount() { return currentTask; }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    
    Worker slave(a, b, c, m);
    
    for(int i=0; i<24; i++) {
        slave.TryWork();
    }
    
    cout << slave.WorkAmount();
}