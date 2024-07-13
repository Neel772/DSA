#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(V);
    pq.push({0, 0});
    int sum = 0;
    while (!pq.empty())
    {
        int node = pq.top().second;
        int edW = pq.top().first;
        pq.pop();
        if(visited[node])
            continue;
        visited[node] = true;
        sum += edW;
        for(auto adjNode: adj[node]){
            int v = adjNode[0];
            int wt = adjNode[1];
            if(!visited[v])
                pq.push({wt, v});
        }
    }
    return sum;
}