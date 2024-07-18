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
    vector<int>dfs(TreeNode* root,int dist,int &cnt)
    {
        if(root==NULL)
            return {};
        if(root->left==NULL && root->right==NULL)
            return {0};
        vector<int>leftD=dfs(root->left,dist,cnt);
        vector<int>rightD=dfs(root->right,dist,cnt);
        for(int iterl:leftD)
        {
            for(int iterr:rightD)
            {
                if(iterl+iterr+2<=dist)
                    ++cnt;
            }
        }
        vector<int>merge;
        for (int iterl:leftD) 
        {
            if (iterl+1<dist) 
                merge.push_back(iterl+1);
        }
        for (int iterr:rightD) 
        {
            if (iterr+1<dist)
                merge.push_back(iterr+1);
        }
        return merge;
    }
    int countPairs(TreeNode* root, int distance) {
        int cnt=0;
        dfs(root,distance,cnt);
        return cnt;
    }
};