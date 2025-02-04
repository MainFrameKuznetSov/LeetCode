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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)
            return {};
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        vector<vector<int>>ans;
        map<int,map<int,multiset<int>>>mp;
        while(!q.empty())
        {
            auto node=q.front().first;
            int vert=q.front().second.first,lvl=q.front().second.second;
            q.pop();
            if(node->left)
                q.push({node->left,{vert-1,lvl+1}});
            if(node->right)
                q.push({node->right,{vert+1,lvl+1}});
            mp[vert][lvl].insert(node->val);
        }
        for(auto it:mp)
        {
            vector<int>temp;
            for(auto j:it.second)
                temp.insert(temp.end(),j.second.begin(),j.second.end());
            ans.push_back(temp);
        }
        return ans;
    }
};