#include <bits/stdc++.h>
using namespace std;

int helper(int n, string& s){
    unordered_map<char, int> mpp;
    for (int i = 0; i < s.length(); i++){
        if(s[i] != '?')
        mpp[s[i]]++;
    }
    int cnt = 0;
    for(auto it: mpp){
        if(it.second >= n){
            cnt += n;
        }
        else{
            cnt += it.second;
        }
    }
    return cnt;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << helper(n, s) << endl;
    }
}