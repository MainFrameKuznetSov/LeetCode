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
class FindElements {
public:
    unordered_set<int>st;
    void recur(TreeNode* &root)
    {
        if(!root)
            return ;
        TreeNode* curr=root;
        st.insert(curr->val);
        if(curr->left)
        {
            curr->left->val=(curr->val)*2+1;
            recur(curr->left);
        }
        if(curr->right)
        {
            curr->right->val=(curr->val)*2+2;
            recur(curr->right);
        }
    }
    FindElements(TreeNode* root) {
        root->val=0;
        //st.insert(0);
        recur(root);
    }
    
    bool find(int target) {
        return (st.count(target)>0?1:0);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */