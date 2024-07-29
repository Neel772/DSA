#include <bits/stdc++.h>
using namespace std;

long long dfs(int node, vector<bool> &vis, int seats, vector<int> &p, vector<vector<int>> &adj)
{
    vis[node] = true;
    int fuel = 0;
    for (auto k : adj[node])
    {
        if (!vis[k]){
              fuel += dfs(k, vis, seats, p, adj);
              p[node] += p[k];
        }
    }
    if(node != 0)
    fuel += (long long)ceil((double)p[node] / seats);
    return fuel;
}
long long minimumFuelCost(vector<vector<int>> &roads, int seats)
{
    int n = roads.size() + 1;
    vector<vector<int>> adj(n);
    for (auto it : roads)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<bool> vis(n, false);
    vector<int> p(n, 1);
    return dfs(0, vis, seats, p, adj);
}

int main(){
    vector<vector<int>> roads = {{3, 1}, {3, 2}, {1, 0}, {0, 4}, {0, 5}, {4, 6}};
    int seats = 2;
    cout << minimumFuelCost(roads, seats);
}