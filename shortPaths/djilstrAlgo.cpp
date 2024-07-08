#include <bits/stdc++.h>
using namespace std;

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>q;
    vector<int>distance(V, 1e9);
    distance[S] = 0;
    q.push({ 0,S });
    while (!q.empty()) {
        int dist = q.top().first;
        int node = q.top().second;
        q.pop();
        for (auto i : adj[node]) {
            if (distance[i[0]] > dist + i[1]) {
                distance[i[0]] = dist + i[1];
                q.push({ distance[i[0]], i[0] });
            }
        }
    }
    return distance;
}

int main() {
    int V = 3;
    vector<vector<int>>adj[] = { {{1,1},{2,6}},{{2,3},{0,1}},{{1,3},{0,6}} };
    int S = 2;
    vector<int>res = dijkstra(V, adj, S);
    for (auto i : res) cout << i << " ";
    cout << endl;
}