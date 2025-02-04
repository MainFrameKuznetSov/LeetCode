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

    int maxHeight(TreeNode* root,int &ans)
    {
        if(!root)
            return 0;
        int L=maxHeight(root->left,ans),R=maxHeight(root->right,ans);
        ans=max(ans,L+R);
        return max(L,R)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        maxHeight(root,ans);
        return ans;
    }
};