class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size(),ans=0;
        for(int i=0;i<n;++i)//O(n)
        {
            for(int j=i;j<n;++j)//O(n)
            {
                int val=nums[j],len=1;
                ans=max(ans,len);
                bool dec=0,inc=0;
                for(int k=j+1;k<n;++k)//O(n)
                {
                    if(k==j+1)
                    {
                        if(nums[k]<nums[j])
                        {
                            dec=1;
                            ++len;
                        }
                        else if(nums[k]>nums[j])
                        {
                            inc=1;
                            ++len;
                        }
                        else
                            break;
                    }
                    else
                    {
                        if(inc && nums[k]>nums[k-1])
                            ++len;
                        else if(dec && nums[k]<nums[k-1])
                            ++len;
                        else 
                            break;
                    }
                }
                ans=max(ans,len);
            }
        }
        return ans;
        /*
            Overall Time complexity:- O(n*n*n)
            Overall Space complexity:- O(1)
        */
    }
};