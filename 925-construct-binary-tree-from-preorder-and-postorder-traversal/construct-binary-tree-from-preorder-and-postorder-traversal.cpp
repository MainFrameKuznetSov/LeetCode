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

    TreeNode* recur(vector<int>&pre,vector<int>&post,int &ind,int low,int high)
    {
        if(ind>=pre.size() || low>high)
            return NULL;
        TreeNode* root=new TreeNode(pre[ind++]);
        if(low==high)
            return root;
        int temp=low;
        while(temp<=high && post[temp]!=pre[ind])
            ++temp;
        if(temp<=high)
        {
            root->left=recur(pre,post,ind,low,temp);
            root->right=recur(pre,post,ind,temp+1,high-1);
        }
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int ind=0,n=preorder.size();
        return recur(preorder,postorder,ind,0,n-1);
    }
};