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

    unordered_map<TreeNode*,TreeNode*>prnt;

    TreeNode* getParents(TreeNode* root,int start)
    {
        TreeNode* src=NULL;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;++i)
            {
                auto curr=q.front();
                q.pop();
                if(curr->val==start)
                    src=curr;
                if(curr->left)
                {
                    q.push(curr->left);
                    prnt[curr->left]=curr;
                }
                if(curr->right)
                {
                    q.push(curr->right);
                    prnt[curr->right]=curr;
                }
            }
        }
        return src;
    }

    int affect(TreeNode* root,TreeNode* src)
    {
        int ans=-1;
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>vis;
        q.push(src);
        vis[src]=1;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;++i)
            {
                //++ans;
                auto curr=q.front();
                q.pop();
                if(curr->left && !vis.count(curr->left))
                {
                    q.push(curr->left);
                    vis[curr->left]=1;
                }
                if(curr->right && !vis[curr->right])
                {
                    q.push(curr->right);
                    vis[curr->right]=1;
                }
                if(prnt.count(curr) && !vis[prnt[curr]])
                {
                    q.push(prnt[curr]);
                    vis[prnt[curr]]=1;
                }
            }
            ++ans;
        }
        return ans;
    }

    int amountOfTime(TreeNode* root, int start) {
        if(!root)
            return 0;
        TreeNode* src=getParents(root,start);
        return affect(root,src);
    }
};