#include <bits/stdc++.h>
using namespace std;

int timer = 1;

void dfs(int node, int parent, vector<bool> &visited, vector<vector<int>> &adj, vector<int>steps, vector<int>low, vector<vector<int>> &ans){
    visited[node] = true;
    steps[node] = timer;
    low[node] = timer;
    timer++;
    for(auto adjNode : adj[node]){
        if(adjNode == parent) continue;
        if(!visited[adjNode]){
            dfs(adjNode, node, visited, adj, steps, low, ans);
            low[node] = min(low[node], low[adjNode]);
            if(low[adjNode] > steps[node])
                ans.push_back({adjNode, node});
        }
        else{
            low[node] = min(low[node], low[adjNode]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections){
    vector<vector<int>> adj(n);
    for(auto i: connections){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
    }
    vector<bool> visited(n, false);
    vector<int> steps(n,-1);
    vector<int> low(n,-1);
    vector<vector<int>> ans;
    dfs(0, -1, visited, adj, steps, low, ans);
    return ans;
}

int main(){
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}, {1, 3}};
    vector<vector<int>> res = criticalConnections(n, connections);
    for(auto i: res){
        cout << i[0] << " "<<i[1] << endl;
    }
}