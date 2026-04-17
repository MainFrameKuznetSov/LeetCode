#define INF 10000000

class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int ans=INF,cnt=0;
        unordered_map<int,int>mp;
        for(int it:nums)
        {
            int temp=0;
            if(mp.count(it))
                ans=min(ans,cnt-mp[it]);
            while(it!=0)
            {
                temp=temp*10+(it%10);
                it/=10;
            }
            mp[temp]=cnt++;
        }
        return ans==INF?-1:ans;
    }
};