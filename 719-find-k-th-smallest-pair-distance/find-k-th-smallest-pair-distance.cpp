class Solution {
public:

    int countPairs(vector<int>&nums,int d) 
    {
        int cnt=0,left=0;
        for (int i=1;i<nums.size();++i) 
        {
            while(nums[i]-nums[left]>d)
                ++left;
            cnt+=i-left;
        }
        return cnt;
    }

    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int low=0,high=nums[n-1]-nums[0];
        while(low<high) 
        {
            int mid=low+(high-low)/2;
            if(countPairs(nums,mid)<k)
                low=mid+1;
            else
                high=mid;
        }
        return low;
    }
    
};


