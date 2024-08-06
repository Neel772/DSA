#include <bits/stdc++.h>
using namespace std;

int num_digits(int n){
    int cnt = 0;
    while(n){
        cnt++;
        n /= 3;
    }
    return cnt;
}

const int N = 2e5 + 20;

int cnt[N], pf[N];

int main(){
    for (int i = 0; i < N - 1; i++){
        cnt[i] = num_digits(i);
        pf[i + 1] = pf[i] + cnt[i];
    }
        int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        r++;
        int sum = pf[r] - pf[l];
        cout << sum + cnt[l] << endl;
    }
}