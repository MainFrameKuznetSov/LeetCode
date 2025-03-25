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
        q.push({root,0LL});
        long long ans=0;
        while(!q.empty())
        {
            int n=q.size();
            long long top=q.front().second,L=-1,R=-1;
            for(int i=0;i<n;++i)
            {
                auto curr=q.front().first;
                long long ind=q.front().second-top;
                q.pop();
                if(curr->left)
                    q.push({curr->left,ind*2+1});
                if(curr->right)
                    q.push({curr->right,ind*2+2});
                if(i==0)
                    L=ind;
                if(i==n-1)
                    R=ind;
                cout<<L<<" "<<R<<"\n";
            }
            ans=max(ans,R-L+1);
        }
        return ans;
    }
};