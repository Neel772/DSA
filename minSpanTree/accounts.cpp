#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    DisjointSet(int siz) : parent(siz), rank(siz)
    {
        for (int i = 0; i < siz; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return;
        if (rank[rootX] < rank[rootY])
        {
            parent[rootX] = rootY;
        }
        else if (rank[rootX] > rank[rootY])
        {
            parent[rootY] = rootX;
        }
        else
        {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

private:
    vector<int> parent;
    vector<int> rank;
};

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
{
    int n = accounts.size();
    DisjointSet ds(n);
    sort(accounts.begin(), accounts.end());
    unordered_map<string, int> mpp;
    for (int i = 0; i < n; i++){
        for (int j = 1; j < accounts[i].size(); j++){
            if(mpp.find(accounts[i][j]) == mpp.end()){
                mpp[accounts[i][j]] = i;
            }
            else{
                ds.Union(i, mpp[accounts[i][j]]);
            }
        }
    }

    vector<string> mergedMail[n];
    for(auto it: mpp){
        string mail = it.first;
        int node = ds.find(it.second);
        mergedMail[node].push_back(mail);
    }

    vector<vector<string>> ans;
    for (int i = 0; i < n; i++){
       if(mergedMail[i].size() == 0) continue;
       sort(mergedMail[i].begin(), mergedMail[i].end());
       vector<string> temp;
       temp.push_back(accounts[i][0]);
       for(auto it : mergedMail[i])
           temp.push_back(it);
       ans.push_back(temp);
    }
    sort(ans.begin(), ans.end());
    return ans;
}