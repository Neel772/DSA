#include <bits/stdc++.h>
using namespace std;

bool helper(int idx, int target, vector<vector<int>> &dp, vector<int> &nums){
    if(target == 0)
        return true;
    if(idx == 0)
        return nums[idx] == target;
        if(dp[idx][target] != -1)
            return dp[idx][target];
    bool not_taken = helper(idx - 1, target, dp, nums);
    bool taken = false;
    if(nums[idx] <= target){
        taken = helper(idx - 1, target - nums[idx], dp, nums);
    }
    return dp[idx][target] =  taken || not_taken;
}

bool canPartition(vector<int> &nums){
    int n = nums.size();
    if(n == 1)
        return false;
    int sum = 0;
    for(auto i: nums)
        sum += i;
    if((sum%2)==1)
        return false;
    vector<vector<int>> dp(n, vector<int>(sum / 2 + 1, -1));
    return helper(n - 1, sum / 2,dp,nums);
}

int main(){
    vector<int> nums = {1,2,3,4,5};
    canPartition(nums) ? cout << "true" << endl : cout << "false" << endl;
}