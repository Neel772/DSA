#include <bits/stdc++.h>
using namespace std;

bool check(int n, int k, int arr[]){
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++){
        int rem = abs(k - arr[i]);
        auto it = mpp.find(rem);
        if(it != mpp.end())
            return true;
        mpp[arr[i]] = i;
    }
    return false;
}

int helper(int n, int k, int arr[]){
    if(n == 1)
        return arr[0];
    if(check(n,k,arr))
        return -1;
    int i = 0;
    while (1)
    {        
        for (int t = arr[n - 1] + i * k; t < arr[n - 1] + (i + 1) * k; t++){
            int cnt = 1;
            for (int j = n - 2; j >= 0; j--)
            {
                int x = ceil((double)(t - arr[j]) / k);
                int y = floor((double)(t - arr[j]) / k);
                if(y%2 == 0 && x%2  == 1 || y % 2 == 0 && x%2 == 0)
                    cnt++;
            }
            if(cnt == n)
                return t;
        }
        i += 2;
    }
    return -1;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        sort(arr, arr + n);
        cout << helper(n, k, arr) << endl;
    }
}