class MagicDictionary {
public:

    unordered_set<string>dict;

    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> dictionary) {
        for(auto i:dictionary)
            dict.insert(i);
    }
    
    bool search(string s) {
        int n=s.size();
        for(int i=0;i<n;++i)
        {
            char pre=s[i];
            for(char ch='a';ch<='z';++ch)
            {
                if(ch==pre)
                    continue;
                s[i]=ch;
                if(dict.count(s))
                    return 1;
            }
            s[i]=pre;
        }
        return 0;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */