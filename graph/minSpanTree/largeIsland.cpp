#include <bits/stdc++.h>
using namespace std;

class disjointSet
{
public:
    vector<int> parent;
    vector<int> siz;
    disjointSet(int n) : parent(n), siz(n)
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            siz[i] = 1;
        }
    }

    int find(int v)
    {
        if (parent[v] == v)
        {
            return v;
        }
        return parent[v] = find(parent[v]);
    }

    void Union(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU == rootV)
            return;
        else
        {
            if (siz[rootU] < siz[rootV])
            {
                parent[rootU] = rootV;
                siz[rootV] += siz[rootU];
            }
            else
            {
                parent[rootV] = rootU;
                siz[rootU] += siz[rootV];   
            }
        }
    }

};

int largestIsland(vector<vector<int>> &grid){
    vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    int n = grid.size();
    disjointSet ds(n * n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++){
            if(grid[i][j] == 1){
                for(auto dir: directions){
                    int row = i + dir.first;
                    int col = j + dir.second;
                    if(row >= 0 && row<n && col>=0 && col<n && grid[row][col] == 1){
                        int node = i * n + j;
                        int adjNode = row * n + col;
                        ds.Union(node, adjNode);
                    }
                }
            }
        }
    }
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++){
            if(grid[i][j] ==1)
                continue;
            set<int> components;
            for(auto it: directions){
                int row = i + it.first;
                int col = j + it.second;
                if (row >= 0 && row < n && col >= 0 && col < n && grid[row][col] == 1)
                {
                    components.insert(ds.find(row * n + col));
                }
            }
            int sizeTotal = 0;
            for(auto i: components)
                sizeTotal += ds.siz[i];
            mx = max(mx, sizeTotal + 1);
        }
    }
    for (int cell = 0; cell < n * n; cell++){
        mx = max(mx, ds.siz[ds.find(cell)]);
    }
    return mx;
}

int main(){
    vector<vector<int>> grid = {{1, 1}, {1, 1}};
    cout << largestIsland(grid);
}