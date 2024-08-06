#include <bits/stdc++.h>
using namespace std;

int helper(int n, vector<int>& nums){
    multiset<long long> odd, even;
    for(auto i: nums){
        if(i%2 == 0)
            even.insert(i);
        else
            odd.insert(i);
    }
    if(odd.size() == 0 || even.size() == 0)
        return 0;
    long long  max_odd = *(odd.rbegin());
    int ans = even.size();
    for (auto i: even){
        if(i <max_odd)
            max_odd += i;
        else{
            ans++;
            break;
        }
    }
    return ans;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        cout << helper(n, nums) << endl;
    }
}