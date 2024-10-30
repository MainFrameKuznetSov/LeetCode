class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int>lis(n,0);
        vector<int>lds(n,0);
        for(int i=0;i<n;++i) 
        {
            int temp=0;
            for(int j=0;j<=i;++j) 
            {
                if(nums[j]<nums[i])
                    temp=max(temp,lis[j]);
            }
            lis[i]=temp+1;
        }
        for(int i=n-1;i>=0;--i) 
        {
            int temp=0;
            for(int j=n-1;j>=i;--j) 
            {
                if(nums[j]<nums[i]) 
                    temp=max(temp,lds[j]);
            }
            lds[i]=temp+1;
        }
        int ans=0;
        for(int i=1;i<n-1;++i) 
        {
            if(lds[i]!=1 && lis[i]!=1)
                ans=max(ans,lis[i]+lds[i]-1);
        }
        return n-ans;
    }
};