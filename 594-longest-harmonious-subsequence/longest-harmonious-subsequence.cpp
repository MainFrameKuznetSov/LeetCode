class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ptr=0,ans=0;
        for(int i=0;i<n;++i)
        {
            while(nums[i]-nums[ptr]>1)
                ++ptr;
            if(nums[i]-nums[ptr]==1)
                ans=max(ans,i-ptr+1);
        }
        return ans;
    }
};