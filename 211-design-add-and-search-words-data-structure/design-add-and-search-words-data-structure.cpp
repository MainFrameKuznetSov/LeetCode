class WordDictionary {
public:

    unordered_map<string,int>mp;

    WordDictionary() {
        
    }
    
    void addWord(string word) {
        mp[word]=1;
    }
    
    bool search(string word) {
        if(mp.count(word))
            return 1;
        int n=word.size(),cnt=0;
        for(int i=0;i<n;++i)
        {
            if(word[i]=='.')
                ++cnt;
        }
        if(cnt==1)
        {
            for(int i=0;i<n;++i)
            {
                if(word[i]=='.')
                {
                    for(char ch='a';ch<='z';++ch)
                    {
                        word[i]=ch;
                        if(mp.count(word))
                            return 1;
                    }
                }
            }
        }
        else
        {
            int a=-1,b=-1;
            for(int i=0;i<n;++i)
            {
                if(word[i]=='.')
                {
                    if(a==-1)
                        a=i;
                    else
                    {
                        b=i;
                        break;
                    }
                }
            }
            if(a==-1 || b==-1)
                return 0;
            for(char c1='a';c1<='z';++c1)
            {
                for(char c2='a';c2<='z';++c2)
                {
                    word[a]=c1;
                    word[b]=c2;
                    if(mp.count(word))
                        return 1;
                }
            }
        }
        return 0;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */