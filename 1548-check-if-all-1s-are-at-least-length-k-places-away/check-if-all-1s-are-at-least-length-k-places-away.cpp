class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n=nums.size(),pre=-1;
        for(int i=0;i<n;++i)
        {
            if(nums[i]==1 && pre==-1)
            {
                pre=i;
                continue;
            }
            if(nums[i]==1)
            {
                if(i-pre-1<k)
                    return 0;
                pre=i;
            }
        }
        return 1;
    }
};