class Solution {
public:

    int helper(int mid,vector<int>&nums)
    {
        int sum=0;
        for(int i:nums)
            sum+=(i%mid==0)?i/mid:i/mid+1;
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(),nums.end());
        int left=1,right=nums[nums.size()-1];
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(helper(mid,nums)<=threshold)
                right=mid-1;
            else
                left=mid+1;
        }
        return left;
    }
};