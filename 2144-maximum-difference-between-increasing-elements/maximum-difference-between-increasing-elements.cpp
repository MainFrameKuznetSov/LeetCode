class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size(),l=0,r=1,ans=-1;
        while(r<n)
        {
            cout<<l<<" "<<r<<"\n";
            if(nums[r]<nums[l])
            {
                ++l;
                //++r;
            }
            else if(nums[r]>nums[l])
            {
                ans=max(ans,nums[r]-nums[l]);
                ++r;
            }
            else
                ++l;
            if(l>=r)
                ++r;
        }
        return ans;
    }
};