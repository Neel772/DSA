#include <bits/stdc++.h>
using namespace std;

int dfs(int node, char pr_color, int &ans, string &s, vector<vector<pair<int, char>>> &adj)
{
    int h = 0;
    vector<int> st;
    for (auto it : adj[node])
    {
        int d = dfs(it.first, s[node], ans, s, adj);
        st.push_back(d);
        h = max(h, d);
    }
    if (pr_color == s[node])
        return 0;

    if (!st.empty())
    {
        sort(st.rbegin(), st.rend()); // Sort in descending order
        if (st.size() > 1)
        {
            ans = max(ans, 1+st[0] + st[1]);
        }
    }
    return 1 + h;
}

int sol(string &s, vector<int> &A)
{
    int n = s.length();
    vector<vector<pair<int, char>>> adj(n);
    for (int i = 0; i < n; i++)
    {
        if (A[i] >= 0)
        { // Check for valid parent index
            adj[A[i]].push_back({i, s[i]});
        }
    }
    int ans = 0;
    int r = dfs(0, 'N', ans, s, adj);
    return ans;
}

int main(){
    string s = "aabababbbaaababababab";
    vector<int> A = {-1,0,1,2,3,4,5,4,7,2,9,9,9,0,13,14,0,16,17,18,18};
    cout << sol(s, A);
}