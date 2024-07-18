#include <bits/stdc++.h>
using namespace std;

int mod = (int)(1e9 + 7);

int perfectSum(int arr[], int n, int sum){
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (arr[i - 1] <= j)
            {
                dp[i][j] += dp[i - 1][j - arr[i - 1]];
            }

            dp[i][j] %= mod;
        }
    }
    return dp[n][sum] % mod;
}

int main(){
    int n = 4;
    int arr[] = {1,0,2,3};
    int sum = 3;
    cout<<perfectSum(arr,n,sum);
}