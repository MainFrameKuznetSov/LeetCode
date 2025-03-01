class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size(),left=0;
        for(int i=0;i<n;++i)
        {
            if(i+1<n && nums[i]==nums[i+1] && nums[i])
            {
                nums[i]*=2;
                nums[i+1]=0;
            }
            if(nums[i])
            {
                if(i!=left)
                    swap(nums[i],nums[left]);
                ++left;
            }
        }
        return nums;
    }
};