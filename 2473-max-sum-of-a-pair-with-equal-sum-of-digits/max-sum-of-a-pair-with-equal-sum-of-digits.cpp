class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int>chk(99,0);
        int ans=-1;
        for(int it:nums)
        {
            int temp=it,s=0;
            while(temp)
            {
                s+=(temp%10);
                temp/=10;
            }
            if(chk[s])
                ans=max(ans,it+chk[s]);
            chk[s]=max(it,chk[s]);
        }
        return ans;
    }
};