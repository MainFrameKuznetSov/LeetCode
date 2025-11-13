class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;++i)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            int j=i+1,k=n-1;
            while(j<k)
            {
                long long sum=nums[i]*1LL+nums[j]*1LL+nums[k]*1LL;
                if(sum==0)
                {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    ++j;
                    --k;
                    while(j<k && nums[j]==nums[j-1])
                        ++j;
                    while(j<k && nums[k]==nums[k+1])
                        --k;
                }
                else if(sum<0)
                    ++j;
                else
                    --k;
            }   
        }
        return ans;
    }
};