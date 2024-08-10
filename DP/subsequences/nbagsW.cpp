#include <bits/stdc++.h>
using namespace std;

// int helper(int idx, int target, int cnt, int n, int* V){
//     if(target == 0 & cnt == n)
//         return 1;
//     if(idx < 0)
//         return 0;
//     int take = 0;
//     if(V[idx] <= target)
//         take = helper(idx - 1, target - V[idx], cnt + 1, n, V);
//     int not_take = helper(idx - 1, target, cnt, n, V);
//     return take + not_take;
// }

int main(){
    int w, nbags, n;
    cin >> w >> nbags >> n;
    int *V = new int[n];
    for (int i = 0; i < n; i++)
        cin >> V[i];
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(w + 1, vector<int>(nbags + 1, -0)));
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= w; j++){
            for (int k = 0; k <= nbags; k++)
            {
                dp[i][j][k] = dp[i - 1][j][k];
                if(k>0 && V[i-1]<=j){
                dp[i][j][k] += dp[i - 1][j - V[i - 1]][k - 1];
                }
            }
        }
    }
    cout << dp[n][w][nbags];
    delete[] V;
}