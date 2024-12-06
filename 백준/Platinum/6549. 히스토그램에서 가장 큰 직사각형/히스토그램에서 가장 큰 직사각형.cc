#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(true) {
        int n;
        cin >> n;
        if(n == 0) break; 
        
        vector<long long> heights(n+2, 0); 
        for(int i=1; i<=n; i++) {
            cin >> heights[i];
        }
        
        stack<int> st;
        long long max_area = 0;
        
        st.push(0);  
        for(int i=1; i<=n+1; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                long long height = heights[st.top()];
                st.pop();
                long long width = i - st.top() - 1;
                max_area = max(max_area, height * width);
            }
            st.push(i);
        }
        
        cout << max_area << '\n';
    }
    
    return 0;
}