/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q)
            return root;
        auto L=lowestCommonAncestor(root->left,p,q),R=lowestCommonAncestor(root->right,p,q);
        if(!L)
            return R;
        else if(!R)
            return L;
        else
            return root;
    }
};