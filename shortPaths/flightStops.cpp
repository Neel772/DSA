#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector < vector<pair<int, int>>>adjList(n);
    for (int i = 0; i < flights.size(); i++) {
        adjList[flights[i][0]].push_back({ flights[i][1],flights[i][2] });
    }
    vector<int>distance(n, 1e9);
    priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({ 0,{src,0} });
    distance[src] = 0;
    while (!pq.empty()) {
        int node = pq.top().second.first;
        int cost = pq.top().second.second;
        int stops = pq.top().first;
        pq.pop();
        if (stops > k) continue;
        for (auto adjNode : adjList[node]) {
            int st = adjNode.first;
            int edW = adjNode.second;
            if (cost + edW < distance[st] && stops <= k) {
                distance[st] = cost + edW;
                pq.push({ stops + 1,{st,distance[st]} });
            }
        }
    }
    if (distance[dst] == 1e9) {
        return -1;
    }
    return distance[dst];
}

int main() {
    int n = 4;
    vector<vector<int>>flights = { {0,1,100},{1,2,100},{2,0,100},{1,3,600},{2,3,200} };
    int src = 0, dst = 3, k = 1;
    cout << findCheapestPrice(n,flights,src,dst,k);
}