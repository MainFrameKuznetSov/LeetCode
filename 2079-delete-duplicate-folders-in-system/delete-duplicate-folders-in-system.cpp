#define F first
#define S second

class Trie 
{

private:

    struct trieNode
    {
        map<string,trieNode*> child;
        string word="";
    }; 

    trieNode* root;
    vector<vector<string>> res;
    unordered_map<string,vector<trieNode*>> m1;
    unordered_set<trieNode*> vis;

public:   

    Trie() 
    {
        root=new trieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(vector<string> &word) 
    {
        trieNode* temp=root;
        for(auto &i: word)
        {
            string ch=i;
            if(temp->child.find(ch)==temp->child.end())
                temp->child[ch]= new trieNode();
            temp=temp->child[ch];
        }
        
    }
    void serialize() 
    {
        trieNode* temp=root;
        for(auto &i:temp->child)
            serialize(i.S,i.F);
    }
    
    string serialize(trieNode* temp,const string &par) 
    {
     
        string subtree="";
        for(auto &i:temp->child)
        {
            string child=serialize(i.S,i.F);
            if(child!="")
            {
                subtree+=child;
                subtree+='$';
            }
        }

        if(!subtree.empty())
        {
            temp->word=subtree;
            m1[subtree].push_back(temp);
        }
            
        string tt=par;
        tt+='#';
        if(!subtree.empty())
            tt+=subtree;
        return tt;
        
    }    

    void mark()
    {
        for(auto &i:m1)
        {
            if((int)i.S.size()>1)
            {
                for(auto &j:i.S)
                    vis.insert(j);
            }
        }
    }

    void solve(trieNode* temp,const string &ch,vector<string> &ans)
    {
        if(vis.find(temp)!=vis.end())
            return;
        ans.push_back(ch);
        res.push_back(ans);
        for(auto &i: temp->child)
            solve(i.S,i.F,ans);
        ans.pop_back();
    }
    void solve()
    {
        vector<string> ans;
        trieNode* temp=root;
        for(auto &i:temp->child)
            solve(i.S,i.F,ans);
    }
    
    
    vector<vector<string>> answer()
    {
        return res;
    }
    
};
class Solution {
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Trie* obj= new Trie();
        for(auto &i:paths)
            obj->insert(i);
        obj->serialize();
        obj->mark();
        obj->solve();
        return obj->answer();
        
    }
};