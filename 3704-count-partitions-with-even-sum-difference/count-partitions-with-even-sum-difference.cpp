class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i:nums)
            sum+=i;
        int curr=0,ans=0;
        for(int i=0;i<n-1;++i)
        {
            curr+=nums[i];
            // cout<<curr<<" "<<(sum-curr)<<"\n";
            if((sum-curr-curr)%2==0)
                ++ans;
        }
        return ans;
    }
};