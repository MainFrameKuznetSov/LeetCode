#define MOD (int)(1e9+7)

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int>mp1,mp2;
        int ans=0;
        for(int i:nums)
        {
            if(i%2==0)
                ans=(ans+mp2[i/2])%MOD;
            
            mp2[i]=(mp2[i]+mp1[i*2])%MOD;
            ++mp1[i];
        }
        return ans;
    }
};