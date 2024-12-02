class Solution {
public:
    int isPrefixOfWord(string sen, string word) {
        sen+=" ";
        string temp="";
        int ans=1;
        for(int i=0;i<sen.size();++i)
        {
            if(sen[i]==' ')
            {
                ++ans;
                temp="";
            }
            else
            {
                temp+=sen[i];
                if(temp==word)
                    return ans;
            }
        }
        return -1;
    }
};