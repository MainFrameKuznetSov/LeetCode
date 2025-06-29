#define MOD 1000000007

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        long long ans=0,l=0,r=nums.size()-1;
        vector<int>psum;
        psum.push_back(1);
        for(auto i=1;i<=r+1;++i)
            psum.push_back((psum.back()<<1)%MOD);

        sort(nums.begin(),nums.end());

        while(l<=r)
        {
            if(nums[l]>target-nums[r])
                --r;
            else
            {
                ans=(ans+(psum[r-l]%MOD))%MOD;
                ++l;
            }
        }
        return (int)ans;
    }
};