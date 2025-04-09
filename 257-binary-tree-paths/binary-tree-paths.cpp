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
    vector<string>ans;
public:

    bool isLeaf(TreeNode* root)
    {
        return (!root->left && !root->right);
    }

    void leaves(TreeNode* root,vector<int>&leaf)
    {
        if(!root)
            return ;
        if(isLeaf(root))
            leaf.push_back(root->val);
        leaves(root->left,leaf);
        leaves(root->right,leaf);
    }

    bool getPath(TreeNode* root,int tar,vector<int>&path)
    {
        if(!root)
            return 0;
        path.push_back(root->val);//Take this into the path
        if(root->val==tar)//If root->val equals root then we have reached out destination 
            return 1;
        if(getPath(root->left,tar,path) || getPath(root->right,tar,path))//Checking if the path exists either in the left or right subtree
            return 1;
        path.pop_back();//Backtracking to check other possibilities
        return 0;
    }

    string getStringEqui(vector<int>path)
    {
        int n=path.size();
        string ans="";
        for(int i=0;i<n-1;++i)
        {
            ans+=to_string(path[i]);
            ans+="->";
        }
        ans+=to_string(path[n-1]);
        return ans;
    }

    void getPath(TreeNode* root, string path) 
    {
        if (!root) 
            return; 

        // Append current node value
        if(!path.empty())//Incase the string has an input before it
            path+="->";
        path+=to_string(root->val);

        // If it's a leaf node, store the path
        if(isLeaf(root)) 
        {
            ans.push_back(path);
            return;
        }

        // Recur for left and right subtrees
        getPath(root->left,path);
        getPath(root->right,path);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        ans.clear();
        if(!root)
            return {};
        getPath(root,"");
        return ans;
    }
};