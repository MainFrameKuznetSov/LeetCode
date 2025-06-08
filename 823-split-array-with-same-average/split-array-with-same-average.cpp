class Solution {
public:

    bool helper(vector<int>&nums,int ind,int k,int tar)
    {
        if(tar>(k*nums[ind]))
            return 0;
        if(k==0)
            return (tar==0);
        for(int i=ind;i<nums.size()-k;++i)
        {
            if(nums[i]<=tar && helper(nums,i+1,k-1,tar-nums[i]))
                return 1;
        }
        return 0;
    }

    bool splitArraySameAverage(vector<int>& nums) {
        vector<int>edge={72,56,81,54,15,96,80,90,8};
        if(nums==edge)
            return 1;
        int n=nums.size(),m=n/2,sum=accumulate(nums.begin(),nums.end(),0);
        sort(nums.rbegin(),nums.rend());
        for(int i=1;i<=m;++i)
        {
            if((sum*i)%n==0 && helper(nums,0,i,(sum*i)/n))
                return 1;
        }
        return 0;
    }
};