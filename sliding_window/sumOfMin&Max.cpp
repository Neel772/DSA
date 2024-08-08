#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    multiset<pair<int, int>> st;
    int sum = 0;
    int i = 0, j = 0;
    while(i<n && j<n){
        st.insert({a[j], j});
        if(j-i+1 == k){
            int mini = st.begin()->first;
            int maxi = st.rbegin()->first;
            sum += (mini + maxi);
            st.erase({a[i], i});
            i++;
        }
        j++;
    }
    cout << sum << endl;
}