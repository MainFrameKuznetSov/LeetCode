class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(),temp=-1;
        if(n==1)
            return ;
        for(int i=0;i<n;++i)
        {
            if(nums[i]==0)
            {
                temp=i;
                break;
            }
        }
        for(int i=temp+1;i<n;++i)
        {
            if(nums[i] && temp!=-1)
            {
                swap(nums[i],nums[temp]);
                ++temp;
            }
        }
    }
};