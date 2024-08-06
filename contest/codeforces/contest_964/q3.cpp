#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, s, m;
        cin >> n >> s >> m;
        vector<int> l(n);
        vector<int> r(n);
        for (int i = 0; i < n; i++){
            cin >> l[i] >> r[i];
        }
        int diff = l[0] - 0;
        if(diff >= s){
            cout << "yes" << endl;
            continue;
        }
        int flag = 0;
        for (int i = 0; i < n - 1; i++)
        {
            diff = l[i + 1] - r[i];
            if(diff >= s){
                cout << "yes" << endl;
                flag = 1;
                break;
            }
        }
        if(flag){
            continue;
        }
        diff = m - r[n - 1];
        if(diff >= s){
            cout << "yes" << endl;
            continue;
        }
        cout << "no" << endl;
    }
}