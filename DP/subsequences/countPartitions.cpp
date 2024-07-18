#include <bits/stdc++.h>
using namespace std;

int mod = (int)(1e9 + 7);

int countPartitions(int n, int d, vector<int> &arr){
    int sum = 0;
    for(auto i: arr)
        sum += i;
    if((sum+d)%2 == 1)
        return 0;
    int k = (sum + d) / 2;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= k; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (arr[i - 1] <= j)
            {
                dp[i][j] += dp[i - 1][j - arr[i - 1]];
            }

            dp[i][j] %= mod;
        }
    }
    return dp[n][k] % mod;
}

int main(){
    int n = 4;
    int d = 0;
    vector<int> arr = {1,1,1,1};
    cout << countPartitions(n, d, arr);
}