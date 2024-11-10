
class Solution
{
public:
    int minimumSubarrayLength(vector<int> &nums, int k)
    {
        if(k==0)
            return 1;

        int ans=INT_MAX;
        vector<int>bits(32,0);
        int l=0,r=0;
        int n=nums.size();
        while(r<n)
        {
            int temp=0;
            for(int i=0;i<32;++i)
            {
                if(nums[r] & (1<<i))
                    ++bits[i];
                if(bits[i])
                    temp|=(1<<i);
            }
            if(temp>=k)
                ans=min(ans,r-l+1);
            while(temp>=k)
            {
                temp=0;
                for(int i=0;i<32;++i)
                {
                    if(nums[l] & (1<<i))
                        --bits[i];
                    if(bits[i])
                        temp|=(1<<i);
                }
                ++l;
                if(temp>=k)
                    ans=min(ans,r-l+1);
            }
            ++r;
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};