class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int n=nums.size(),l=-1,r=-1,out=-1;
        for(int i=0;i<n;++i)
        {
            if(!(minK<=nums[i] && nums[i]<=maxK))
                out=i;
            if(nums[i]==minK)
                l=i;
            if(nums[i]==maxK)
                r=i;
            ans+=max(0,min(l,r)-out);
        }
        return ans;
    }
};