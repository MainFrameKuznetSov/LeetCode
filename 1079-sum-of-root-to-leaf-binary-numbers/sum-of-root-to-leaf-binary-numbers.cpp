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

    vector<string>collectedStrings;

    bool isLeaf(TreeNode* root)
    {
        return (!(root->left) && !(root->right));
    }

    void recur(TreeNode* root,string binary)
    {
        bool f=0;
        if(isLeaf(root))
        {
            binary+=to_string(root->val);
            collectedStrings.push_back(binary);
        }
        if(root->left)
        {
            f=1;
            binary+=to_string(root->val);
            recur(root->left,binary);
        }
        if(f)
            binary.pop_back();
        if(root->right)
        {
            binary+=to_string(root->val);
            recur(root->right,binary);
        }
    }

    int sumRootToLeaf(TreeNode* root) 
    {
        recur(root,"");
        int n=collectedStrings.size(),ans=0;
        for(string str:collectedStrings)
        {
            int sum=0,ind=0;
            for(int j=str.size()-1;j>=0;--j)
            {
                int digit=str[j]-'0';
                sum+=(digit<<ind);
                ++ind;
            }
            ans+=sum;
        }
        return ans;
    }
};