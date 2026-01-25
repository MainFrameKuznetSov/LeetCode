class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),mn=(int)1e9;
        for(int i=k-1;i<n;++i)
        {
            int pre=i+1-k;
            mn=min(mn,nums[i]-nums[max(0,pre)]);
        }
        return mn;

    }
};