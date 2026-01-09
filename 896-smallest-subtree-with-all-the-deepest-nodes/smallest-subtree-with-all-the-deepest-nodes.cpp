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

    pair<int,TreeNode*> findSubtree(TreeNode* root)
    {
        if(!root)
            return {0,NULL};
        
        auto leftNode=findSubtree(root->left),rightNode=findSubtree(root->right);
        if(leftNode.first==rightNode.first)
            return {leftNode.first+1,root};
        else if(leftNode.first>rightNode.first)
            return {leftNode.first+1,leftNode.second};
        else
            return {rightNode.first+1,rightNode.second};

    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return findSubtree(root).second;
    }
};