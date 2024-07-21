#include <bits/stdc++.h>
using namespace std;

int helper(int idx, int target, vector<vector<int>> &dp, vector<int> &coins){
    if(idx == 0){
        if(target%coins[idx] == 0){
            return target / coins[idx];
        }
        else
            return 1e9;
    }
    if(dp[idx][target] != -1)
        return dp[idx][target];
    int not_taken = helper(idx - 1, target, dp, coins);
    int take = 1e9;
    if (coins[idx] <= target){
        take = 1 + helper(idx, target - coins[idx], dp, coins);
    }
    return dp[idx][target] = min(take, not_taken);
}

int coinChange(vector<int> &coins, int amount){
    if(amount == 0)
        return 0;
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    for (int i = 0; i < n; i++){
        dp[i][0] = 0;
    }
    int ans = helper(n - 1, amount, dp, coins);
    if (ans >= 1e9)
        return -1;
    return ans;
}

int main(){
    vector<int> coins = {1,2,5};
    int amount = 11;
    cout << coinChange(coins, amount);
}