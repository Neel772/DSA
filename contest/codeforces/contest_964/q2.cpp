#include <bits/stdc++.h>
using namespace std;

int check(int x1, int x2, int y1, int y2){
    int s1 = 0, s2 = 0;
    if(x1 > y1){
        s1++;
    }
    else if(x1 < y1){
        s2++;
    }
    if (x2 > y2)
    {
        s1++;
    }
    else if (x2 < y2)
    {
        s2++;
    }
    return s1 > s2;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int a1, a2, b1, b2;
        cin >> a1 >> a2 >> b1 >> b2;
        if(a1 == a2 && a2 == b1 && b1 == b2){
            cout << 0 << endl;
            continue;
        }
        int s1 = 0, s2 = 0;
        int win = 0;
        win += check(a1, a2, b1, b2);
        win += check(a1, a2, b2, b1);
        win += check(a2, a1, b1, b2);
        win += check(a2, a1, b2, b1);
        cout << win << endl;
    }
}