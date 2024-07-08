#include <bits/stdc++.h>
using namespace std;

    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int count = 0;
        int sz = 1;
        int lo = 0, hi = 0;
        while (lo < n) {
            if (colors[hi] != colors[(hi + 1) % n]) {
                sz++;
                hi = (hi + 1) % n;
                if (sz == 3) {
                    sz = 1;
                    lo++;
                    hi = lo;
                    count++;
                }
            }
            else {
                lo++;
                hi = lo;
                sz = 1;
            }
        }
        return count;
    }

    int main() {
        vector<int>colors = { 1,0,1,0,1,1,0 };
        cout << numberOfAlternatingGroups(colors);
    }