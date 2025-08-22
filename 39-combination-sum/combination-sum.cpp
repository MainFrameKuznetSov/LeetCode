class Solution {
public:

    void f(int ind,int W,vector<int>&v,vector<vector<int>>&ans,vector<int>&temp,vector<vector<int>>&dp)
    {
        if(W==0)
        {
            ans.push_back(temp);
            return ;
        }

        int n=v.size();
        if(ind==n)
            return ;

        if(v[ind]<=W)//Take
        {
            temp.push_back(v[ind]);
            f(ind,W-v[ind],v,ans,temp,dp);
            temp.pop_back();
        }

        f(ind+1,W,v,ans,temp,dp);//Nottake
        
        return ;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>>ans;
        vector<int>temp;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        f(0,target,candidates,ans,temp,dp);
        return ans;
    }
};