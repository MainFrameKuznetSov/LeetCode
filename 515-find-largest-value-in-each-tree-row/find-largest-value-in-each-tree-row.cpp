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

    vector<int>v;

    void preOrder(TreeNode* node,int lvl)
    {
        if(!node)
            return ;
        if(v.size()<=lvl)
            v.push_back(INT_MIN);
        v[lvl]=max(v[lvl],node->val);
        preOrder(node->left,lvl+1);
        preOrder(node->right,lvl+1);
    }

    vector<int> largestValues(TreeNode* root) {

        if(root)
        {
            preOrder(root,0);
            return v;
        }
        return {};
    }
};