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
    void DFS(TreeNode* node,int s1,int s2,string &curr,string &s1r,string &s2r)
    {
        if(!node)
            return;
        if(node->val==s1)
            s1r=curr;
        if(node->val==s2)
            s2r=curr;
        curr+='L';
        DFS(node->left,s1,s2,curr,s1r,s2r);
        curr.pop_back();
        curr+='R';
        DFS(node->right,s1,s2,curr,s1r,s2r);
        curr.pop_back();
        return;
    }
    string getDirections(TreeNode* root, int start, int dest) {
        string s1r="",s2r="",curr="";
        DFS(root,start,dest,curr,s1r,s2r);
        int i=0,m=s1r.size(),n=s2r.size();
        while(i<m && i<n && s1r[i]==s2r[i])
            ++i;
        string temp(m-i,'U');
        int sz=max(0,n-i);
        string ans=temp+s2r.substr(i,sz);
        return ans;
    }
};