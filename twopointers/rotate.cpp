#include <bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    int cnt = 0;
    int i = 0;
    int temp = nums[i];
    while (cnt < n)
    {
        int idx = (i + k) % n;
        int temp1 = nums[idx];
        nums[idx] = temp;
        cnt++;
        i = idx;
        temp = temp1;
    }
}

int main(){
    vector<int> nums = {-1, 100, 3, 99};
    int k = 2;
    rotate(nums, k);
}