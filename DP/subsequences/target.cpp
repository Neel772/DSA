#include <bits/stdc++.h>
using namespace std;

bool helper(int idx, int target, vector<vector<int>> &dp, vector<int>arr){
    if(target == 0)
        return true;
    if(idx == 0)
        return arr[0] == target;
    if(dp[idx][target] != -1)
        return dp[idx][target];
    bool not_taken = helper(idx - 1, target, dp, arr);
    bool take = false;
    if(arr[idx] <= target){
        take = helper(idx - 1, target - arr[idx], dp, arr);
    }
    return dp[idx][target] =  take || not_taken;
}

bool isSubsetSum(vector<int> arr, int sum){
    vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1));
    return helper(arr.size() - 1, sum, dp, arr);
}

int main(){
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    (isSubsetSum(arr, sum)) ? cout << "true"<<endl : cout << "false" << endl;
}