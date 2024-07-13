#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    DisjointSet(int siz) : parent(siz+1), rank(siz+1)
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

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
    vector<vector<int>> visited(n, vector<int>(m, 0));
    DisjointSet ds(n * m);
    int count = 0;
    vector<int> ans;
    vector<pair<int, int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
    for (int i = 0; i < q.size(); i++)
    {
        int x = q[i][0];
        int y = q[i][1];
        if(visited[x][y] == 1){
            ans.push_back(count);
            continue;
        }
        visited[x][y] = 1;
        count++;
        for(auto dir: directions){
            int adjR = x + dir.first;
            int adjC = y + dir.second;
            if(adjR >=0 && adjR <n && adjC>=0 && adjC < m){
                if(visited[adjR][adjC] == 1){
                    int node = x * m + y;
                    int adjNode = adjR * m + adjC;
                    if(ds.find(adjNode) != ds.find(node)){
                        ds.Union(adjNode, node);
                        count--;
                    }
                }
            }
        }
        ans.push_back(count);
    }
    return ans;
}

int main(){
    int n = 4;
    int m = 5;
    vector<vector<int>> q = {{1, 1}, {0, 1}, {3, 3}, {3, 4}};
    vector<int> res = numOfIslandsII(n, m, q);
    for(auto i:  res)
        cout << i << " ";
    cout << endl;
}