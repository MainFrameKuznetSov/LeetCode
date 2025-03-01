/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void getParents(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&prnt)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
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

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>prnt;
        getParents(root,prnt);
        unordered_map<TreeNode*,bool>vis;
        queue<pair<TreeNode*,int>>q;
        q.push({target,0});
        //vis[target]=1;
        vector<int>ans;
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;++i)
            {
                auto node=q.front().first;
                int dist=q.front().second;
                if(dist==k)
                    ans.push_back(node->val);
                vis[node]=1;
                q.pop();
                if(dist>k)
                    continue;
                if(node->left && !vis[node->left])
                    q.push({node->left,dist+1});
                if(node->right && !vis[node->right])
                    q.push({node->right,dist+1});
                if(prnt.count(node) && !vis[prnt[node]])
                    q.push({prnt[node],dist+1});
            }
        }
        return ans;
    }
};