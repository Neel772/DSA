#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 8;
    int dp[k][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < k; i++){
        for (int j = 1; j <= n; j++){
            dp[i][j] = dp[i][j - 1];
            if(a[j-1]<=i && a[j-1]>0){
                dp[i][j] += dp[i / a[j - 1]][j-1] + 1;
            }
        }
    }
    cout << dp[k - 1][n];
}