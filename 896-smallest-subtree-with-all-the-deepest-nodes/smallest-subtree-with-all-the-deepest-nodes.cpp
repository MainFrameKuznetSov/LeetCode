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

    int maxD;
    unordered_map<int,int>nodeMap;

    void mapFiller(TreeNode* root,int depth)
    {
        if(!root)
            return ;
        nodeMap[root->val]=depth;
        maxD=max(maxD,depth);
        mapFiller(root->left,depth+1);
        mapFiller(root->right,depth+1);
    }

    TreeNode* findLCA(TreeNode* root)
    {
        if(!root)
            return NULL;
        if(nodeMap[root->val]==maxD)
            return root;
        
        TreeNode* leftNode=findLCA(root->left);
        TreeNode* rightNode=findLCA(root->right);

        if(leftNode && rightNode)
            return root;
        if(!leftNode)
            return rightNode;
        return leftNode;

    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        nodeMap[root->val]=0;
        maxD=0;
        mapFiller(root,0);//O(n)
        return findLCA(root);//O(n)
        //Two-pass solution
    }
};