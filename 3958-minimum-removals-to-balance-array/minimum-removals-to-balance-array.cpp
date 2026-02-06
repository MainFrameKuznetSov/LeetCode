class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),ptr=0,mx=1;
        for(int i=0;i<n;++i)
        {
            while(nums[i]*1LL>1LL*nums[ptr]*k)
                ++ptr;
            mx=max(mx,i-ptr+1);
        }
        return n-mx;
    }
};