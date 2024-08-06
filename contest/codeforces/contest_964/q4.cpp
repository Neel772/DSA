#include <bits/stdc++.h>
using namespace std;

bool isSubsequence(string &s, string &t)
{
    int n = s.size();
    int m = t.size();
    int j = 0;
    for (int i = 0; i < n && j < m; ++i)
    {
        if (s[i] == t[j] || s[i] == '?')
        {
            ++j;
        }
    }
    return j == m;
}

void solve()
{
    
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string s, t;
        cin >> s >> t;

        if (isSubsequence(s, t))
        {
            int n = s.size();
            int m = t.size();
            int j = 0;
            for (int i = 0; i < n; ++i)
            {
                if (j < m && (s[i] == t[j] || s[i] == '?'))
                {
                    s[i] = t[j];
                    ++j;
                }
                else if (s[i] == '?')
                {
                    s[i] = 'a';
                }
            }
            cout << "YES" << endl;
            cout << s << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
