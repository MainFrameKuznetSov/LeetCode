#define rep(i,a,n) for(int i=a;i<n;++i)
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size(),ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;++i)
        {
            for(int j=n-1;j>i;--j)
            {
                int p=nums[i]*nums[j];
                unordered_set<int>st;
                for(int k=i+1;k<j;++k)
                {
                    if(p%nums[k]==0)
                    {
                        if(st.count(p/nums[k]))
                            ans+=8;
                        else
                            st.insert(nums[k]);
                    }
                }
            }
        }
        return ans;
    }
};