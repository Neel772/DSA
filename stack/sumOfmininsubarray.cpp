#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int sumSubarrayMins(vector<int> &A)
{
    stack<pair<int, int>> in_stk_p, in_stk_n;
    vector<int> left(A.size()), right(A.size());

    // Initialize left and right vectors
    for (int i = 0; i < A.size(); i++)
        left[i] = i + 1; // Distance to the start (for first element)
    for (int i = 0; i < A.size(); i++)
        right[i] = A.size() - i; // Distance to the end (for last element)

    for (int i = 0; i < A.size(); i++)
    {
        // For Previous Less Element (PLE)
        while (!in_stk_p.empty() && in_stk_p.top().first >= A[i])
        {
            in_stk_p.pop();
        }
        left[i] = in_stk_p.empty() ? i + 1 : i - in_stk_p.top().second;
        in_stk_p.push({A[i], i});

        // For Next Less Element (NLE)
        while (!in_stk_n.empty() && in_stk_n.top().first > A[i])
        {
            auto x = in_stk_n.top();
            in_stk_n.pop();
            right[x.second] = i - x.second;
        }
        in_stk_n.push({A[i], i});
    }

    int ans = 0;
    int mod = 1e9 + 7;
    for (int i = 0; i < A.size(); i++)
    {
        ans = (ans + (long long)A[i] * left[i] * right[i]) % mod;
    }
    return ans;
}

int main()
{
    vector<int> A = {3, 1, 2, 4};
    cout << sumSubarrayMins(A) << endl; // Output should be 17
    return 0;
}
