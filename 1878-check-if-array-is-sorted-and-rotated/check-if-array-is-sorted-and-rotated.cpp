class Solution {
public:
    bool check(vector<int>& nums) 
    {
        int n=nums.size(),odd=0;
        for(int i=0;i<n;++i)
        {
            if(nums[i]<nums[(i+n-1)%n])
                ++odd;
            if(odd>1)
                return false;
        }
        return true;
    }
};