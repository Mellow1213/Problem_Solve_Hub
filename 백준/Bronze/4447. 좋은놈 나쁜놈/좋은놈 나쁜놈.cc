#include <iostream>

using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int N;
    string letter;
        
    cin >> N;
    cin.ignore();
    for(int i=0; i<N; i++){
        int G = 0;
        int B = 0;
        
        getline(cin, letter);
        
        for(const auto& p : letter){
            if(p == 'G' || p == 'g')
                G++;
            else if(p == 'B' || p == 'b')
                B++;
        }
        
        string judge;
        cout << letter << " is ";
        if(G>B)
            judge = "GOOD";
        else if(G<B)
            judge = "A BADDY";
        else
            judge = "NEUTRAL";
        
        cout << judge << '\n';
    }
}