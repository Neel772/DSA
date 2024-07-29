#include <bits/stdc++.h>
using namespace std;

vector<int> dice = {1, 2, 3, 4, 5, 6};

int snakesAndLadders(vector<vector<int>> &board)
{
    int n = board.size();
    std::queue<std::pair<int, int>> q;
    std::vector<bool> visited(n * n + 1, false);
    int ans = -1;

    q.push({0, 1}); // {steps, node}
    visited[1] = true;

    while (!q.empty())
    {
        auto [steps, node] = q.front();
        q.pop();

        if (node == n * n)
        {
            ans = steps;
            break;
        }

        for (int it = 1; it <= 6; ++it)
        {
            int newNode = node + it;
            if (newNode > n * n)
                break;

            int original = newNode - 1;
            int row = n - 1 - (original / n);
            int col = (row % 2 == 1) ? (original % n) : (n - 1 - (original % n));
            if(visited[newNode])
                continue;
            visited[newNode] = true;
            if (board[row][col] != -1)
            {
                q.push({steps + 1, board[row][col]});
                }
                else
                {
                    q.push({steps + 1, newNode});
                }
        }
    }

    return ans;
}

int main(){
    vector<vector<int>> board = {
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 35, -1, -1, 13, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, 15, -1, -1, -1, -1}};
    cout << snakesAndLadders(board);
}