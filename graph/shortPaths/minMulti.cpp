#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int> &arr, int start, int end){
    if(start == end)
        return 0;
    int mod = 1e5;
    vector<int> dist(100000, INT_MAX);
    queue<pair<int,int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while (!pq.empty())
    {
        int node = pq.front().second;
        int steps = pq.front().first;
        pq.pop();
        for(auto i: arr){
            int adjNode = (node * i) % mod;
            if (steps + 1 < dist[adjNode]){
                dist[adjNode] = steps + 1;
                if(adjNode == end)
                    return steps + 1;
                pq.push({steps + 1, adjNode});
            }
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {3,4,65};
    int start =7, end = 66175;
    cout << minimumMultiplications(arr, start, end);
}