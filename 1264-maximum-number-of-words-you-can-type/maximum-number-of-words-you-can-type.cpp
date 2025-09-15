class Solution {
public:

    bool isPossible(string word,string broken)
    {
        for(char c:word)
        {
            if(broken.find(c)!=string::npos)
                return false;
        }
        return true;
    }

    int canBeTypedWords(string text, string brokenLetters) {
        istringstream iss(text);
        vector<string>words;
        string word;
        while(iss>>word)
            words.push_back(word);
        int ans=0;
        for(string w:words)
            ans+=isPossible(w,brokenLetters)?1:0;
        return ans;
    }
};