class Solution {
public:
    int dp[10][10][2];
    int recur(int ind,int cnt,string s,bool flag)
    {
        if(ind>=s.size())
            return cnt;
        if(dp[ind][cnt][flag]!=-1)
            return dp[ind][cnt][flag];
        int ans=0,lim=flag?s[ind]-'0':9;
        for(int i=0;i<=lim;++i)
            ans+=recur(ind+1,(i==1)?cnt+1:cnt,s,(flag&i==lim));
        return dp[ind][cnt][flag]=ans;
    }
    int countDigitOne(int n) {
        memset(dp,-1,sizeof(dp));
        string s=to_string(n);
        int ans=recur(0,0,s,1);
        return ans;
    }
};