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
    TreeNode* createBinaryTree(vector<vector<int>>& desc) {
        int n=desc.size();
        unordered_set<int>st;
        unordered_map<int,TreeNode*>node;
        for(int i=0;i<n;++i)
        {
            int prnt=desc[i][0];
            int child=desc[i][1];
            bool flag=desc[i][2];
            st.insert(child);
            if(node.find(prnt)==node.end())
                node[prnt]=new TreeNode(prnt);
            if(node.find(child)==node.end())
                node[child]=new TreeNode(child);
            if(flag)
                node[prnt]->left=node[child];
            else
                node[prnt]->right=node[child];
        }
        for(int i=0;i<n;++i)
        {
            int prnt=desc[i][0];
            if(st.find(prnt)==st.end())
                return node[prnt];
        }
        return NULL;
    }
};