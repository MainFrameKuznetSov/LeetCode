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
    static int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int ans=0;
        while(!q.empty())
        {
            int n=q.size();
            vector<int>temp(n,0),v(n,0);
            for(int i=0;i<n;++i)
                temp[i]=i;
            for(int i=0;i<n;++i)
            {
                auto node=q.front();
                q.pop();
                v[i]=node->val;
                if(node->left) 
                    q.push(node->left);
                if(node->right) 
                    q.push(node->right);
            }
            sort(temp.begin(),temp.end(),[&](int a, int b)
            {
                return v[a]<v[b];
            }
            );
            for(int i=0;i<n;)
            {
                int j=temp[i];
                if (j!=i)
                {
                    ++ans;
                    swap(temp[i], temp[j]);
                }
                else 
                    ++i;
            }
        }
        return ans;
    }
};