class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),mx=0;
        vector<int>dp(n,1),prev(n,-1);
        for(int i=1;i<n;++i)
        {
            for(int j=0;j<i;++j)
            {
                if(nums[i]%nums[j]==0 && dp[i]-1<dp[j])
                {
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
            if(dp[i]>dp[mx])
                mx=i;
        }
        vector<int>ans;
        int curr=mx;
        while(curr>=0)
        {
            ans.push_back(nums[curr]);
            curr=prev[curr];
        }
        return ans;
    }
};