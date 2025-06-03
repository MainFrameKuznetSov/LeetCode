class Solution {
public:

    int f(int ind,int rind,string &ring,string &key,vector<vector<int>>&dp)
    {
        if(ind==key.size())
            return 0;
        if(dp[ind][rind]!=-1)
            return dp[ind][rind];
        int steps=INT_MAX,temp=rind,cnt=0,sz=ring.size();
        while(cnt<sz)
        {
            if(key[ind]==ring[temp])
                steps=min(steps,1+cnt+f(ind+1,temp,ring,key,dp));
            ++cnt;
            ++temp;
            temp=temp%sz;
        }
        cnt=0;
        temp=rind;
        while(cnt<sz)
        {
            if(key[ind]==ring[temp])
                steps=min(steps,1+cnt+f(ind+1,temp,ring,key,dp));
            ++cnt;
            --temp;
            temp+=sz;
            temp=temp%sz;
        }
        return dp[ind][rind]=steps;
    }

    int findRotateSteps(string ring, string key) {
        vector<vector<int>>dp(101,vector<int>(101,-1));
        return f(0,0,ring,key,dp);
    }
};