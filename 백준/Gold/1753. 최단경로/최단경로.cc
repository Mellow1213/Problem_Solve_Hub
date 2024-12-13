#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge
{
    int end;
    int value;
    Edge(int e, int v) : end(e), value(v) {}
};

void Dijkstra(vector<int> &distance, int begin, vector<vector<Edge>> &adj)
{
    distance[begin] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, begin});

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (dist > distance[now])
            continue;

        for (const auto &edge : adj[now])
        {
            int nextNode = edge.end;
            int nextDist = dist + edge.value;

            if (nextDist < distance[nextNode])
            {
                distance[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        }
    }
}

int main()
{
    int V, E;
    cin >> V >> E;
    vector<vector<Edge>> adj(V + 1);
    vector<int> distance(V + 1, 1e9);

    int startNode;
    cin >> startNode;

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(Edge(v, w));
    }

    Dijkstra(distance, startNode, adj);

    for (int i = 1; i <= V; i++)
    {
        if (distance[i] == 1e9)
            cout << "INF\n";
        else
            cout << distance[i] << "\n";
    }

    return 0;
}
