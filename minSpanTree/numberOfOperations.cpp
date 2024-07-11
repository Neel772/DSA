#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool>&visited, vector<vector<int>>&adj){
    visited[node] = true;
    for(auto i: adj[node]){
        if(!visited[i])
            dfs(i, visited, adj);
    }
}

int makeConnected(int n, vector<vector<int>> &connections)
{
    if(connections.size() < n-1)
        return -1;
    vector<vector<int>> adjList(n);
    for(auto i: connections){
        adjList[i[0]].push_back(i[1]);
        adjList[i[1]].push_back(i[0]);
    }
    vector<bool> visited(n, false);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if(!visited[i]){
        dfs(i, visited, adjList);
        count++;
        }
    }
    return count - 1;
}

int main(){
    int n = 6;
    vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,2},{1,3}};
    cout << makeConnected(n, connections);
}