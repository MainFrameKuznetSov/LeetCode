class Solution {
public:
    bool isCircularSentence(string sen) {
        vector<string>words;
        int start=0,end;
        while((end=sen.find(' ',start))!=string::npos)
        {
            words.push_back(sen.substr(start,end-start));
            start=end+1;
        }
        words.push_back(sen.substr(start));
        int n=words.size();
        for(int i=0;i<n-1;++i)
        {
            int len=words[i].size();
            if(words[i][len-1]!=words[i+1][0])
                return false;
        } 
        int len=words[n-1].size();
        if(words[n-1][len-1]!=words[0][0])
            return false;
        return true;
    }
};