#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    int cnt = 2;
    int i = 0, j = 0;
    while (j < nums.size())
    {
        if (nums[i] == nums[j])
        {
            if (cnt == 0)
                nums[j] = INT_MAX;
            else
                cnt--;
            j++;
        }
        else
        {
            cnt = 2;
            i = j;
        }
    }
    i = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] != INT_MAX)
        {
            swap(nums[i], nums[j]);
            i++;
        }
    }
    return i;
}

int main(){
    vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
    cout << removeDuplicates(nums);
}