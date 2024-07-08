#include <bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>> &times, int n, int k){
    vector<vector<pair<int,int>>> adjList(n);
    for (auto i: times){
        adjList[i[0]-1].push_back({i[1]-1, i[2]});
    }
    // for (int i = 0; i < n;i++){
    //     cout << i << "->";
    //     for (int j = 0; j < adjList[i].size(); j++)
    //     {
    //         cout << adjList[i][j].first << adjList[i][j].second << ",";
    //     }
    //     cout << endl;
    // }
        vector<int> t(n, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0,k-1});
    t[k - 1] = 0;
    while (!pq.empty())
    {
        int node = pq.top().second;
        int timeTaken = pq.top().first;
        pq.pop();
        for(auto adjNode: adjList[node]){
            int v = adjNode.first;
            int edW = adjNode.second;
            if(timeTaken + edW < t[v]){
                t[v] = timeTaken + edW;
                pq.push({t[v], v});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(t[i] == 1e9){
            // cout << i << endl;
            return -1;
        }
    }
    return *max_element(t.begin(), t.end());
}

int main(){
    int n = 4;
    int k = 2;
    vector<vector<int>> times = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    cout << networkDelayTime(times, n, k);
}