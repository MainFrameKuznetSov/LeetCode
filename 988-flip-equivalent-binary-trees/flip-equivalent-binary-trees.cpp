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

    bool hobe(TreeNode* a,TreeNode* b)
    {
        if(!a && !b)
            return 1;
        if(!a || !b || a->val!=b->val)
            return 0;
        return (hobe(a->left,b->left) || hobe(a->left,b->right)) && (hobe(a->right,b->left) || hobe(a->right,b->right));
    }

    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return hobe(root1,root2);
    }
};