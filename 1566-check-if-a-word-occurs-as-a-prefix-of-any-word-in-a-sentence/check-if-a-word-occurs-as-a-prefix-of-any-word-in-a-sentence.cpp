class Solution {
public:
    int isPrefixOfWord(string sen, string word) {
        sen+=" ";
        string temp="";
        int ans=0;
        for(int i=0;i<sen.size();++i)
        {
            if(sen[i]==' ')
            {
                ++ans;
                string nx="";
                for(int j=0;j<temp.size();++j)
                {
                    nx+=temp[j];
                    if(nx==word)
                        return ans;
                }
                temp="";
            }
            else
                temp+=sen[i];
        }
        return -1;
    }
};