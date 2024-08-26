/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(!root)
            return {};
        vector<Node*>v={root};
        deque<int>q;
        while(!v.empty())
        {
            auto curr=v.back();
            v.pop_back();
            q.push_front(curr->val);
            for(auto iter:curr->children)
            {
                if(iter)
                    v.push_back(iter);
            }
        }
        return vector<int>(q.begin(),q.end());
    }
};