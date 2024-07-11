#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    DisjointSet(int siz) : parent(siz),rank(siz){
        for (int i = 0; i < siz; i++){
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int rootX = find(x);
        int rootY = find(y);
        if(rootX == rootY)
            return;
        if(rank[rootX] < rank[rootY]){
            parent[rootX] = rootY;
        }
        else if(rank[rootX] > rank[rootY]){
            parent[rootY] = rootX;
        }
        else{
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

    private:
        vector<int> parent;
        vector<int> rank;
};

int removeStones(vector<vector<int>> &stones)
{
    int n = stones.size();
    DisjointSet ds(n);
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]){
                ds.Union(i, j);
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++){
        if(ds.find(i) == i)
            count++;
    }
    return n-count;
}

int main(){
    vector<vector<int>> stones = {{0, 0}, {1,1}, {2,2}, {3,3},{3,4}, {5,5}};
    cout << removeStones(stones);
}