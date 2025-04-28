class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0,ptr=0;
        int n=nums.size();
        for(int i=0,j=0;i<n;++i)
        {
            ptr+=nums[i];
            while(ptr*(i-j+1)>=k)
                ptr-=nums[j++];
            ans+=i-j+1;
        }
        return ans;
    }
};