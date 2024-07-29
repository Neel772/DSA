#include <bits/stdc++.h>
using namespace std;

int nonSpecialCount(int l, int r)
{
    int cnt = 0;
    for (int num = l; num <= r; num++)
    {
        vector<int> temp;
        int sqrt_n = static_cast<int>(sqrt(num));
        for (int i = 1; i <= sqrt_n; i++)
        {
            if (num % i == 0)
                temp.push_back(i);
            if (i != num / i)
                temp.push_back(num / i);
        }
        if (temp.size() != 3)
            cnt++;
    }
    return cnt;
}

int main(){
    int l = 5, r = 7;
    cout << nonSpecialCount(l, r);
}