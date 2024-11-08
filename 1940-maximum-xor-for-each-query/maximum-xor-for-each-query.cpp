class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maxi) {
        int prod=0,n=nums.size();
        for(int i=0;i<n;++i)
            prod=prod^nums[i];
        vector<int>ans(n);
        int msk=(1<<maxi);
        --msk;
        for(int i=0;i<n;++i)
        {
            ans[i]=prod^msk;
            prod=prod^nums[n-1-i];
        }
        return ans;
    }
};