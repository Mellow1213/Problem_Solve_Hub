#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<vector<pair<int, int>>> adjacency_list;

int BFS(int start) {
    vector<int> distances(adjacency_list.size(), -1);
    queue<int> q;
    int sum = 0;
    
    q.push(start);
    distances[start] = 0;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (auto& neighbor : adjacency_list[node]) {
            int next_node = neighbor.first;
            int weight = neighbor.second;
            if (distances[next_node] == -1) {
                distances[next_node] = distances[node] + weight;
                q.push(next_node);
                sum += distances[next_node];
            }
        }
    }
    
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int node, link;
    cin >> node >> link;
    adjacency_list.assign(node + 1, vector<pair<int, int>>());
    
    for (int i = 0; i < link; i++) {
        int g, l;
        cin >> g >> l;
        adjacency_list[g].push_back({l, 1});
        adjacency_list[l].push_back({g, 1});
    }
    
    vector<int> baconNum(node);
    for (int i = 1; i <= node; i++) {
        baconNum[i - 1] = BFS(i);
    }
    
    int min_bacon = *min_element(baconNum.begin(), baconNum.end());
    for (int i = 0; i < node; i++) {
        if (baconNum[i] == min_bacon) {
            cout << i + 1;
            break;
        }
    }
    
    return 0;
}
