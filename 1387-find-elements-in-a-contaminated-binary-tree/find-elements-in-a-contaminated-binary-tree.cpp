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
    TreeNode* R;
    void recur(TreeNode* &root)
    {
        if(!root)
            return ;
        TreeNode* curr=root;
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
        recur(root);
        R=root;
    }
    
    bool find(int target) {
        queue<TreeNode*>q;
        q.push(R);
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;++i)
            {
                auto node=q.front();
                q.pop();
                if(node->val==target)
                    return 1;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return 0;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */