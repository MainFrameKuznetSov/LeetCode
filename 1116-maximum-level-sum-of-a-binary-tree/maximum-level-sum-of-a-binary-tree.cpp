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
    int maxLevelSum(TreeNode* root) {
        int mx=INT_MIN,ans=0,lvl=0;
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty())
        {
            ++lvl;
            int temp=0,n=q.size();
            for(int i=n;i>0;--i)
            {
                auto node=q.front();
                q.pop();
                temp+=node->val;

                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            
            if(temp>mx)
            {
                mx=temp;
                ans=lvl;
            }
        }
        return ans;
    }
};