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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& del) 
    {
        vector<TreeNode*>vect;
        unordered_map<int,int>mp;
        for(auto iter:del)
        {
            mp[iter]++;
        }
        queue<pair<TreeNode*,int>>q;
        if(mp.find(root->val)!=mp.end())
            q.push({root,1});
        else
        {
            q.push({root,0});
            vect.push_back(root);
        }
        while(!q.empty())
        {
            auto iter=q.front();
            q.pop();
            TreeNode* curr=iter.first;
            int delet=iter.second;
            if(delet==0)
            {
                if(curr->left!=NULL && mp.find(curr->left->val)!=mp.end())
                {
                    q.push({curr->left,1});
                    curr->left=NULL;
                }
                else
                {
                    if(curr->left!=NULL)
                    q.push({curr->left,0});
                }

                if(curr->right!=NULL && mp.find(curr->right->val)!=mp.end())
                {
                    q.push({curr->right,1});
                    curr->right=NULL;
                }
                else
                {
                    if(curr->right!=NULL)
                    q.push({curr->right,0});
                }
            }
            else
            {
                if(curr->left!=NULL && mp.find(curr->left->val)!=mp.end())
                {
                    q.push({curr->left,1});
                    curr->left=NULL;
                }
                else
                {
                    if(curr->left!=NULL)
                    {
                        q.push({curr->left,0});
                        vect.push_back(curr->left);
                    }
                }

                if(curr->right!=NULL && mp.find(curr->right->val)!=mp.end())
                {
                    q.push({curr->right,1});
                    curr->right=NULL;
                }
                else
                {
                    if(curr->right!=NULL)
                    {
                        q.push({curr->right,0});
                        vect.push_back(curr->right);
                    }
                }
                curr->left=NULL;
                curr->right=NULL;
            }
        }
        return vect;
    }
};