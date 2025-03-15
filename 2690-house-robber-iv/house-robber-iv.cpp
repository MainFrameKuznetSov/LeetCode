class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int low=1,high=*max_element(nums.begin(),nums.end()),n=nums.size();
        while(low<high) 
        {
            int mid=low+(high-low)/2,curr=0;
            for(int i=0;i<n;++i) 
            {
                if(nums[i]<=mid) 
                {
                    ++curr;
                    ++i; 
                }
            }
            if(curr>=k)
                high=mid;
            else
                low=mid+1;
        }

        return low;
    }
};