#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();
    vector<int> o(26, 0), t(26, 0);
    for (auto i : s1)
        o[i - 'a']++;
    int i = 0, j = 0;
    while (j < n2)
    {
        t[s2[j] - 'a']++;
        if (j - i + 1 == n1)
        {
            if (o == t)
                return true;
            t[s2[i] - 'a']--;
            i++;
        }
        j++;
    }
    return false;
}

int main(){
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    cout << checkInclusion(s1, s2) << endl;
}