#define MOD (int)(1e9+7)
#define ll long long

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        int n=nums.size();
        vector<ll> dp(n+1),psum(n+1);
        multiset<int>st;
        dp[0]=1;
        psum[0]=1;
        int i=0,j=0;
        while(i<n)
        {
            st.insert(nums[i]);
            while(j<=i && *st.rbegin()-*st.begin()>k)
            {
                st.erase(st.find(nums[j]));
                ++j;
            }
            if(j-1>=0)
                dp[i+1]=(psum[i]-psum[j-1]+MOD)%MOD;
            else
                dp[i+1]=psum[i]%MOD;
            psum[i+1]=(psum[i]+dp[i+1])%MOD;
            ++i;
        }
        return dp[n];
    }
};