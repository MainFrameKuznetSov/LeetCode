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
private:
    void genInorder(TreeNode *root,vector<int> &inorder)
    {
        if(!root)
            return;
        genInorder(root->left,inorder);
        inorder.push_back(root->val);
        genInorder(root->right,inorder);
    }

private:
    TreeNode *genTree(vector<int> &inorder,int l,int r)
    {
        if(r<l)
            return NULL;
        int mid=l+(r-l)/2;
        TreeNode *node=new TreeNode(inorder[mid]);
        node->left=genTree(inorder,l,mid-1);
        node->right=genTree(inorder,mid+1,r);
        return node;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;
        genInorder(root,inorder);
        return genTree(inorder,0,inorder.size()-1);
    }
};