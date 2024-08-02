#include<bits/stdc++.h>
using namespace std;

bool flipEquiv(TreeNode *root1, TreeNode *root2)
{
    if (!root1 && !root2)
        return true;
    else if (!root1 || !root2)
        return false;
    if (root1->left != root2->left && root1->right != root2->right)
    {
        if (root1->left == root2->right && root1->right == root2->left)
        {
            swap(root1->left, root1->right);
        }
        else
            return false;
    }
    bool l = flipEquiv(root1->left, root2->left);
    bool r = flipEquiv(root1->right, root2->right);

    return l && r;
}

int main(){
    
}