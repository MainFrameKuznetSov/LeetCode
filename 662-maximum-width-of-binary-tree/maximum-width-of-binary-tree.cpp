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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        long long ans=0;
        while(!q.empty())
        {
            long long n=q.size(),top=q.front().second,first=-1,last=-1;
            for(int i=0;i<n;++i)
            {
                auto node=q.front().first;
                long long ind=q.front().second-top;
                q.pop();
                if(node->left)
                    q.push({node->left,ind*2+1});
                if(node->right)
                    q.push({node->right,ind*2+2});
                if(i==0)
                    first=ind;
                if(i==n-1)
                    last=ind;
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};