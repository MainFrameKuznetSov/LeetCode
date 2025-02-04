/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool help(TreeNode* L,TreeNode* R)
    {
        if(!L || !R)
            return L==R;
        if(L->val!=R->val)
            return 0;
        return (help(L->left,R->right) && help(L->right,R->left));
    }

    bool isSymmetric(TreeNode* root) {
        return (!root || help(root->left,root->right));
    }
};