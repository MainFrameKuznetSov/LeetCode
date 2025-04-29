#define ll long long 
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        ll mx=0,cnt=0,left=0,right=0,ans=0;
        for(ll i:nums)
            mx=max(mx,i);
        while(right<n)
        {
            if(nums[right]==mx)
                ++cnt;
            while(cnt>=k)
            {
                if(nums[left]==mx)
                    --cnt;
                ++left;
                ans+=(n-right);
            }
            ++right;
        }
        return ans;
    }
};