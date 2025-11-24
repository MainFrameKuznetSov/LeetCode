class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int msk=0,n=nums.size();
        vector<bool>ans(n);
        for(int i=0;i<n;++i)
        {
            msk=((msk<<1)+nums[i])%5;
            ans[i]=(msk==0)?1:0;
        }
        return ans;
    }
};