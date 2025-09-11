class Solution {
public:
    long long helper(int i, int parent, bool flip, int flipd, int k,
                     vector<vector<int>>& mp, vector<int>& arr,
                     vector<vector<vector<long long>>>& dp) {

        if(flipd>k) 
            flipd=k;

        if(dp[i][flip][flipd]!=-1)
            return dp[i][flip][flipd];

        int sign=flip?-1:1;
        long long res=sign*arr[i];

        for(auto &x:mp[i]) 
        {
            if(x==parent) 
                continue;
            res+=helper(x,i,flip,flipd+1,k,mp,arr,dp);
        }

    
        if(flipd==k) 
        {
            long long flipped=sign*-1*arr[i];
            for(auto &x:mp[i]) 
            {
                if(x==parent) 
                    continue;
                flipped+=helper(x,i,!flip,1,k,mp,arr,dp);
            }
            res=max(res,flipped);
        }

        return dp[i][flip][flipd]=res;
    }

    long long subtreeInversionSum(vector<vector<int>>& gp, vector<int>& arr, int k) {
        int n=arr.size();
        vector<vector<int>>mp(n);

        for(auto&x:gp) 
        {
            mp[x[0]].push_back(x[1]);
            mp[x[1]].push_back(x[0]);
        }

        vector<vector<vector<long long>>> dp(
            n,vector<vector<long long>>(2,vector<long long>(k+1,-1)));

        return helper(0,-1,false,k,k,mp,arr,dp);
    }
};