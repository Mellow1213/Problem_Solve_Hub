#include <iostream>
using namespace std;

class Fibo{
    private:
        int memo[40] = {0,};
        int Fibonacci(int n){
            if(n == 0){
                return 0;
            }
            else if(n == 1){
                return 1;
            }
            else{
                if(memo[n] <= 0){
                    memo[n] = Fibonacci(n-1) + Fibonacci(n-2);
                }
                return memo[n];
            }
        };
        
    public:
        void ShowCnt(int n){
            if(n == 0) { cout << "1 0" << '\n'; return; }
            
            cout << Fibonacci(n-1) << ' ' << Fibonacci(n) << '\n';
        };
};


int main()
{
    int N;
    Fibo f;
    cin >> N;
    
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        f.ShowCnt(temp);
    }
}