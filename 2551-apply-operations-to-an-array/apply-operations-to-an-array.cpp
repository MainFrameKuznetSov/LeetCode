class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=1;i<n;++i)
        {
            if(nums[i-1]==nums[i])
            {
                nums[i-1]*=2;
                nums[i]=0;
            }
        }
        int c=0;
        for(int i=0;i<n;++i)
        {
            if(nums[i]==0)
                ++c;
            else
                ans.push_back(nums[i]);
        }
        for(int i=1;i<=c;++i)
            ans.push_back(0);
        return ans;
    }
};