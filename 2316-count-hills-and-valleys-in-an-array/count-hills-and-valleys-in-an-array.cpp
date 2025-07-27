class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n=nums.size(),cnt=0;
        for(int i=1,j=0;i<n-1;++i)
        {
            if((nums[i]>nums[j] && nums[i]>nums[i+1]) || (nums[i]<nums[j] && nums[i]<nums[i+1]))
            {
                ++cnt;
                j=i;
            } 
        }
        return cnt;
    }
};