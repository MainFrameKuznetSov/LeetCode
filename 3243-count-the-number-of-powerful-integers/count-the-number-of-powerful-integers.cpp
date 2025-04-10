#define ll long long

class Solution {
public:

    ll countValidNumbers(int pos,int tight,string &num,string &suf,int lim,int len,vector<vector<ll>>&dp) 
    {
        if(pos==len) 
            return 1;
        if(dp[pos][tight]!=-1) 
            return dp[pos][tight];
        ll lo=0,cnt=0;
        int hi=tight?min(lim,num[pos]-'0'):lim;
        int sufStart=len-suf.size();
        if(sufStart<=pos) 
        {
            lo=suf[pos-sufStart]-'0';
            hi=min(hi,suf[pos-sufStart]-'0');
        }
        for(int d=lo;d<=hi;++d)
            cnt+=countValidNumbers(pos+1,tight&&(d==num[pos]-'0'),num,suf,lim,len,dp);
        return dp[pos][tight]=cnt;
    }

    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string up=to_string(finish),low=to_string(start-1);
        int ulen=up.size(),llen=low.size();
        ll ucnt=0,lcnt=0;
        vector<vector<ll>>dp(17,vector<ll>(2,-1));
        if(s.size()<=ulen) 
            ucnt=countValidNumbers(0,1,up,s,limit,ulen,dp);
        dp.assign(17,vector<ll>(2,-1));
        if(s.size()<=llen) 
            lcnt=countValidNumbers(0,1,low,s,limit,llen,dp);
        return ucnt-lcnt;
    }
};