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
    deque<int> s(k), g(k);
    int sum = 0;
    int i = 0;
    for (; i < k;i++){
        while(!s.empty() && a[s.back()] >= a[i])
            s.pop_back();
        while(!g.empty() && a[g.back()] <= a[i])
            g.pop_back();
        s.push_back(i);
        g.push_back(i);
    }

    for (; i < n;i++){
        sum += (a[s.front()] + a[g.front()]);
        while(!s.empty() && s.front() <= i-k)
            s.pop_front();
        while(!g.empty() && g.front() <= i-k)
            g.pop_front();
        
        while (!s.empty() && a[s.back()] >= a[i])
            s.pop_back();
        while (!g.empty() && a[g.back()] <= a[i])
            g.pop_back();
        s.push_back(i);
        g.push_back(i);
    }

    sum += (a[s.front()] + a[g.front()]);
    cout << sum << endl;
}