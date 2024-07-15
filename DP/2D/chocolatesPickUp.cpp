#include <bits/stdc++.h>
using namespace std;


int helper(int i, int j1, int j2, int n, int m, vector<vector<vector<int>>> &dp, vector<vector<int>> &grid){
    if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e9;
    if(i == n-1){
        if(j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    if(dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    int maxi = INT_MIN;
    for (int d1 = -1; d1 <= 1; d1++)
    {
        for (int d2 = -1; d2 <= 1; d2++){
            int ans;
            if(j1 == j2)
                ans = grid[i][j1] + helper(i + 1, j1+d1, j2+d2, n, m, dp, grid);
            else
                ans = grid[i][j1] + grid[i][j2]+ helper(i + 1, j1+d1, j2+d2, n, m, dp, grid);
            maxi = max(maxi, ans);
        }
    }
    return dp[i][j1][j2] = maxi;
}

int solve(int n, int m, vector<vector<int>> &grid){
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m,vector<int>(m,-1)));
    return helper(0, 0, m - 1, n, m, dp, grid);
}

int main(){
    int n = 4;
    int m = 3;
    vector<vector<int>> grid = {{3, 1, 1}, {2, 5, 1}, {1, 5, 5}, {2, 1, 1}};
    cout << solve(n, m, grid);
}
