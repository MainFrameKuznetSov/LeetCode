#define ll long long
#define MOD 1000000007

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

    ll ans=0LL;

    void sum(TreeNode* root)
    {
        if(!root)
            return ;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=1;i<=n;++i)
            {
                auto node=q.front();
                ans+=node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                q.pop();                
            }
        }
    }

    ll res=0LL;//max(sub_sum*(tot-sub_sum))

    ll recur(TreeNode* root)
    {
        if(!root)
            return 0;
        // if(!root->left && !root->right)
        //     return root->val;

        ll lsum=recur(root->left),rsum=recur(root->right);   
        ll sub_sum=(root->val+lsum+rsum);
        res=max(res,sub_sum*(ans-sub_sum));      

        return sub_sum;

    }

    int maxProduct(TreeNode* root) {
        sum(root);
        recur(root);
        res%=MOD;
        return (int)res;
    }
};