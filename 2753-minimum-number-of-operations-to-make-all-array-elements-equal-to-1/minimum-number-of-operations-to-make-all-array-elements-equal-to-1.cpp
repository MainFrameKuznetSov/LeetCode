class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(),one=0,gcd=0;
        for(int i:nums)
        {
            if(i==1)
                ++one;
            gcd=__gcd(gcd,i);
        }
        if(one)
            return n-one;
        if(gcd!=1)
            return -1;
        int ans=n;
        for(int i=0;i<n;++i)
        {
            gcd=0;
            for(int j=i;j<n;++j)
            {
                gcd=__gcd(gcd,nums[j]);
                if(gcd==1)
                {
                    ans=min(ans,j-i+1);
                    break;
                }
            }
        }
        return ans+n-2;
    }
};