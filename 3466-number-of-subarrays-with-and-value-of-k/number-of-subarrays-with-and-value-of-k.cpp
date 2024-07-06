class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        long long ans=0;
        unordered_map<long long,long long>prev;
        for(int i=0;i<n;++i)
        {
            unordered_map<long long,long long>curr;
            if(nums[i]==k)
                ++ans;
            curr[nums[i]]=1;
            for(auto iter:prev)
            {
                long long val=(iter.first & nums[i]);
                if(val==k)
                    ans+=iter.second;
                curr[val]+=iter.second;
            }
            prev=curr;
        }
        return ans;
    }
};