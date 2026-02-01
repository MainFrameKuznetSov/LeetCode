class Solution {
public:
    int minimumCost(vector<int>& nums) {
        if(nums.size()==3)
            return nums[0]+nums[1]+nums[2];
        int ans=nums[0];
        int comp=100,comp2=100,index=-1;
        for(int i=nums.size()-1;i>=1;--i)
        {
            if(comp>nums[i])
            {
                comp=nums[i];
                index=i;
            }
        }
        ans+=comp;
        comp=100;
        for(int i=1;i<index;++i)
        {
            if(comp>nums[i])
                comp=nums[i];
        }
        for(int i=index+1;i<nums.size();++i)
        {
            if(comp2>nums[i])
                comp2=nums[i];
        }    
        return ans+min(comp,comp2);
    }
};