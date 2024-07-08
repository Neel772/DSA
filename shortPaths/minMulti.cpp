#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int> &arr, int start, int end){
    long long mod = 1e5;
    priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<pair<int, long long>>> pq;
    pq.push({0, start});
    while(!pq.empty()){
        long long node = pq.top().second;
        int steps = pq.top().first;
        pq.pop();
        if(node == end){
            return steps;
        }
        for(auto i: arr){
            long long adjNode = (node * i) % mod;
            if(adjNode <= end)
            pq.push({steps + 1, adjNode});
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {3,4,65};
    int start =7, end = 66175;
    cout << minimumMultiplications(arr, start, end);
}