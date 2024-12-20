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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int f=0;
        while(!q.empty())
        {
            int n=q.size();
            vector<TreeNode*>t(n);
            for(int i=0;i<n;++i)
            {
                auto top=q.front();
                q.pop();
                if(top->right!=NULL)
                    q.push(top->right);
                if(top->left!=NULL)
                    q.push(top->left);
                if(f)
                {
                    t[i]=top;
                    if(i*2>=n)
                        swap(t[i]->val,t[n-i-1]->val);
                }
            }
            f=1-f;
        }
        return root;
    }
};