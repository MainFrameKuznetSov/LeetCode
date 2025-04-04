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
#define F first
#define S second
class Solution {
public:

    pair<int,TreeNode*> solve(TreeNode* root)
    {
        if(!root)
            return {0,NULL};
        auto L=solve(root->left),R=solve(root->right);
        if(L.F==R.F)
            return {L.F+1,root};
        else if(L.F>R.F)
            return {L.F+1,L.S};
        else
            return {R.F+1,R.S};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return solve(root).S;
    }
};