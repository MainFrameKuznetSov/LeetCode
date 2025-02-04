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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        int flip=0;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>lvl(n);
            for(int i=0;i<n;++i)
            {
                auto node=q.front();
                q.pop();
                int ind=flip?n-i-1:i;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                lvl[ind]=node->val;
            }
            flip=1-flip;
            ans.push_back(lvl);
        }
        return ans;
    }
};