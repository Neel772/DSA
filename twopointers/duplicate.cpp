#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 0; i <= n; i++)
        cin >> a[i];
    int left = 1, right = n;
    while(left<right){
        int mid = (left + right) / 2;
        int cnt = 0;
        for (int num : a)
        {
            if(num <= mid)
                cnt++;
        }
        if(cnt >mid)
            right = mid;
        else
            left = mid + 1;
    }
    cout << left << endl;
}
