class WordFilter {
public:

    unordered_map<string,int>mp;

    WordFilter(vector<string>& words) {
        int n=words.size();
        for(int i=0;i<n;++i)
        {
            string word=words[i];
            int len=word.size();
            for(int j=1;j<=len;++j)
            {
                string sub=word.substr(0,j);
                for(int k=0;k<len;++k)
                {
                    string sub2=word.substr(k,len);
                    mp[sub+"&"+sub2]=i+1;
                }
            }
        }
    }
    
    int f(string pref, string suff) {
        string sub=pref+"&"+suff;
        return mp[sub]-1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(pref,suff);
 */