class Solution {
public:
    char kthCharacter(int k) {
        string ans="a";
        while(ans.size()<=k)
        {
            string temp="";
            for(int i=0;i<ans.size();++i)
                temp+=(char)(ans[i]+1);
            ans+=temp;
        }
        return ans[k-1];
    }
};