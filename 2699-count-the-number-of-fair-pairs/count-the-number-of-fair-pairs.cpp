class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;++i) 
        {
            auto u=upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i]);
            auto l=lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i]);
            ans+=(u-l);
        }
        return ans;
    }
};