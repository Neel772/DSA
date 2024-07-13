#include <bits/stdc++.h>
using namespace std;

int countPaths(int n, vector<vector<int>> &roads){
    vector<vector<pair<int, int>>> adjList(n);
    for (auto it: roads){
        adjList[it[0]].push_back({it[1], it[2]});
        adjList[it[1]].push_back({it[0], it[2]});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    vector<int> distance(n, 1e9);
    distance[0] = 0;
    vector<int> ways(n, 0);
    ways[0] = 1;
    int mod = (int)(1e9 + 7);
    while (!pq.empty())
    {
        int node = pq.top().second;
        int steps = pq.top().first;
        pq.pop();
        for(auto adjNode : adjList[node]){
            int v = adjNode.first;
            int edW = adjNode.second;
            if(steps + edW < distance[v]){
                ways[v] = ways[node];
                distance[v] = steps + edW;
                pq.push({distance[v], v});
            }
            else if (steps + edW == distance[v]){
                ways[v] = (ways[v] + ways[node]) % mod;
            }
        }
    }
    return ways[n - 1] % mod;
}

int main(){
    vector<vector<int>> roads = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
    int n = 7;
    cout << countPaths(n, roads);
}