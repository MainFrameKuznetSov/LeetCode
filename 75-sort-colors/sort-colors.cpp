class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c0=0,c1=0,c2=0,n=nums.size(),cur=0;
        for(int i=0;i<n;++i)
        {
            if(nums[i]==0)
                ++c0;
            else if(nums[i]==1)
                ++c1;
            else
                ++c2;
        }
        for(int i=1;i<=c0;++i)
            nums[cur++]=0;
        for(int i=1;i<=c1;++i)
            nums[cur++]=1;
        for(int i=1;i<=c2;++i)
            nums[cur++]=2;
    }
};