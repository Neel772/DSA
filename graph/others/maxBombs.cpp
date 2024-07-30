#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int maxi = 0;
int dfs(int node, vector<int> &count, vector<vector<int>> &adj)
{
    count[node]++;
    for (auto it : adj[node])
    {
        if (count[it] == 0)
            count[node] += (count[it] = dfs(it, count, adj));
        else
        {
            count[node] += count[it];
        }
    }
    maxi = max(maxi, count[node]);
    return count[node];
}
int maximumDetonation(vector<vector<int>> &bombs)
{
    int n = bombs.size();
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        ll x1, y1, r1;
        x1 = bombs[i][0];
        y1 = bombs[i][1];
        r1 = bombs[i][2];
        for (int j = 0; j < n; j++)
        {
            ll x2, y2, r2;
            x2 = bombs[j][0];
            y2 = bombs[j][1];
            r2 = bombs[j][2];
            ll x = abs(x1 - x2);
            ll y = abs(y1 - y2);
            if (x * x + y * y <= r1 * r1 && i!=j)
            {
                adj[i].push_back(j);
            }
        }
    }
    vector<int> count(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (count[i] == 0)
        {
            count[i] = dfs(i, count, adj);
        }
    }
    return maxi;
}


int main(){
    vector<vector<int>> bombs = {
        {1, 2, 3},
        {2, 3, 1},
        {3, 4, 2},
        {4, 5, 3},
        {5, 6, 4}};
   
    cout << maximumDetonation(bombs);
}