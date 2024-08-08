#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 0; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i <= n; i++){
        if(a[i] == i+1)
            continue;
        if (a[a[i] - 1] == a[i])
        {
            cout << a[i] << endl;
            break;
        }
        else
            swap(a[i], a[a[i] - 1]);
    }
}
