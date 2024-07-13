#include <bits/stdc++.h>
using namespace std;

class disjointSet{
    public:
        disjointSet(int n) : parent(n), siz(n){
            for (int i = 0; i < n; i++){
                parent[i] = i;
                siz[i] = 1;
            }
        }

        int find(int v){
            if(parent[v] == v){
                return v;
            }
            return parent[v] = find(parent[v]);
        }

        void Union(int u, int v){
            int rootU = find(u);
            int rootV = find(v);
            if(rootU == rootV)
                return;
            else{
                if(siz[rootU] < siz[rootV] ){
                    parent[rootU] = rootV;
                    siz[v] += siz[u];
                }
                else{
                    parent[rootV] = rootU;
                    siz[u] += siz[v];
                }
            }
        }

        private:
            vector<int> parent;
            vector<int> siz;
};

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<pair<int, pair<int, int>>> edges;
    for (int u = 0; u < V; u++){
        for (int j = 0; j < adj[u].size(); j++){
            int v = adj[u][j][0];
            int w = adj[u][j][1];
            edges.push_back({w, {u,v}});
        }
    }
    sort(edges.begin(), edges.end());
    int mst = 0;
    disjointSet ds(V);
    for (int i = 0; i < edges.size(); i++){
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        int wt = edges[i].first;

        if(ds.find(u) != ds.find(v)){
            mst += wt;  
            ds.Union(u, v);
        }
    }
    return mst;
}

int main(){
    
}