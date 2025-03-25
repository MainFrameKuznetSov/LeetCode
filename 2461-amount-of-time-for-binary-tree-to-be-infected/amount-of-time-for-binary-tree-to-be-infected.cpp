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

private:
    unordered_map<TreeNode*,TreeNode*>prnt;

public:

    TreeNode* getParents(TreeNode* root,int start)
    {
        queue<TreeNode*>q;
        TreeNode* ans=NULL;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;++i)
            {
                auto node=q.front();
                q.pop();
                if(node->val==start)
                    ans=node;
                if(node->left)
                {
                    q.push(node->left);
                    prnt[node->left]=node;
                }
                if(node->right)
                {
                    q.push(node->right);
                    prnt[node->right]=node;
                }
            }
        }
        return ans;
    }

    int affect(TreeNode* src)
    {
        unordered_map<TreeNode*,bool>vis;
        vis[src]=1;
        queue<TreeNode*>q;
        q.push(src);
        vis[src]=1;
        int ans=0;
        while(!q.empty())
        {
            int n=q.size();
            bool f=0;
            for(int i=0;i<n;++i)
            {
                auto node=q.front();
                q.pop();
                if(node->left && !vis[node->left])
                {
                    q.push(node->left);
                    vis[node->left]=1;
                    f=1;
                }
                if(node->right && !vis[node->right])
                {
                    q.push(node->right);
                    vis[node->right]=1;
                    f=1;
                }
                if(prnt.count(node) && !vis[prnt[node]])
                {
                    q.push(prnt[node]);
                    vis[prnt[node]]=1;
                    f=1;
                }
            }
            if(f)
                ++ans;
        }
        return ans;
    }

    int amountOfTime(TreeNode* root, int start) {
        if(!root)
            return 0;
        TreeNode* src=getParents(root,start);
        return affect(src);
    }
};