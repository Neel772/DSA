#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 0; i <= n; i++)
        cin >> a[i];
    int slow = a[0], fast = a[slow];
    while(slow != fast){
        slow = a[slow];
        fast = a[a[fast]];
    }
    slow = 0;
    while(slow != fast){
        slow = a[slow];
        fast = a[fast];
    }
    cout << slow << endl;
}
