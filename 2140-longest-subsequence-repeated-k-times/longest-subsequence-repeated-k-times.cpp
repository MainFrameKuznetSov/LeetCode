class Solution {
public:

    bool helper(string &s,string ans,int k)
    {
        int chk=0,n=s.size();
        for(int i=0;i<n;++i)
        {
            if(s[i]==ans[chk])
                ++chk;
            if(chk==ans.size())
            {
                --k;
                if(k==0)
                    return 1;
                chk=0;
            }
        }
        return k<=0;
    }

    string recur(string &s,string &ans,int k)
    {
        int sum=0;
        string res="";
        for(char c='z';c>='a';--c)
        {
            if(helper(s,ans+c,k))
            {
                ans+=c;
                string temp=c+recur(s,ans,k);
                if(sum<temp.size())
                {
                    res=temp;
                    sum=temp.size();
                }
                ans.pop_back();
            }
        }
        return res;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        string ans="";
        return recur(s,ans,k);
    }
};