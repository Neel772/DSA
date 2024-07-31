#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    bool val;
    bool isLeaf;
    Node *topLeft;
    Node *topRight;
    Node *bottomLeft;
    Node *bottomRight;

    Node()
    {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node *_topLeft, Node *_topRight, Node *_bottomLeft, Node *_bottomRight)
    {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

Node *connect(vector<vector<int>> &grid,int n, int r_s, int r_e, int c_s, int c_e)
{
    if (n == 0)
        return NULL;
    Node *tl = connect(grid,n / 4, r_s, r_e - (n / 2), c_s, c_e - (n / 2));
    Node *tr = connect(grid,n / 4, r_s, r_e - (n / 2), c_s + (n / 2), c_e);
    Node *bl = connect(grid,n / 4, r_s + (n / 2), r_e, c_s, c_e - (n / 2));
    Node *br = connect(grid,n / 4, r_s + (n / 2), r_e, c_s + (n / 2), c_e);
    if (!tl)
    {
        tl = new Node(grid[r_s][c_s], true);
    }
    if (!tr)
    {
        tr = new Node(grid[r_s][c_s], true);
    }
    if (!bl)
    {
        bl = new Node(grid[r_s][c_s], true);
    }
    if (!br)
    {
        br = new Node(grid[r_s][c_s], true);
    }
    if (tl->val == tr->val && tr->val == bl->val && bl->val == br->val)
    {
        return tl;
    }
    Node *temp = new Node(1, false, tl, tr, bl, br);
    return temp;
}

Node *construct(vector<vector<int>> &grid)
{
    int n = grid.size();
    return connect(grid, n, 0, n - 1, 0, n - 1);
}

int main(){
    vector<vector<int>> grid = {{0, 1}, {1, 0}};
    Node *ans = construct(grid);
}