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
    vector<int>depth,level,mx1,mx2;

    int height(TreeNode* root,int lvl)
    {
        if(!root)
            return 0;
        level[root->val]=lvl;
        depth[root->val]=max(height(root->left,lvl+1),height(root->right,lvl+1))+1;
        if(mx1[lvl]<depth[root->val])
        {
            mx2[lvl]=mx1[lvl];
            mx1[lvl]=depth[root->val];
        }
        else if(mx2[lvl]<depth[root->val])
            mx2[lvl]=depth[root->val];
        return depth[root->val];
    }

    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        depth.resize(100001,0);
        level.resize(100001,0);
        mx1.resize(100001,0);
        mx2.resize(100001,0);

        height(root,0);

        for(int i=0;i<queries.size();++i)
        {
            int lvl=level[queries[i]];
            queries[i]=(mx1[lvl]==depth[queries[i]]?mx2[lvl]:mx1[lvl]) + (lvl-1);
        }

        return queries;
    }
};