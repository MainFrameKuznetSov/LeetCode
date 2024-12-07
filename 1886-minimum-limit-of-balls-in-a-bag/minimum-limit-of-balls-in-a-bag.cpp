class Solution {
public:
    bool check(vector<int>& nums,int mid,int maxOperations)
    {
        int cnt=0;
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]<mid) 
                continue;
            else
            {
                if(nums[i]%mid==0)
                    cnt+=(nums[i]/mid)-1;
                else 
                    cnt+=nums[i]/mid;
            }
        }
        if(cnt<=maxOperations) 
            return true;
        return false;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left=1; 
        int right=INT_MIN; 
        for(auto iter:nums)
            right=max(right,iter);
        int ans=-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(check(nums,mid,maxOperations))
            {
                ans=mid;
                right=mid-1;
            }
            else 
                left=mid+1;
        }
        return ans;
    }
};