class Solution {
public:
    string answerString(string word, int frnds) {
        if(frnds==1)
            return word;
        int n=word.size(),len=n-frnds+1;
        string ans="";
        for(int i=0;i<n;++i)
        {
            string temp=word.substr(i,len);
            ans=max(ans,temp);
            //cout<<temp<<"\n";
        }
        return ans;
    }
};