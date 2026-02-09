class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int ans=0;
        for(;;)
        {
            int n=nums.size();
            bool f=1;
            for(int i=0;i<n-1;++i)
            {
                if(nums[i]>nums[i+1])
                {
                    f=0;
                    break;
                }
            }
            if(f)
                break;
            int mn=INT_MAX,ind=0;
            for(int i=0;i<n-1;++i)
            {
                int curr=nums[i]+nums[i+1];
                if(curr<mn)
                {
                    mn=curr;
                    ind=i;
                }
            }
            nums[ind]+=nums[ind+1];
            nums.erase(nums.begin()+ind+1);
            ++ans;
        }
        return ans;
    }
};