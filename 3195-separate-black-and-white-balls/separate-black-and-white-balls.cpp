class Solution {
public:
    long long minimumSteps(string s) {
        int n=s.size();
        long long ans=0,blk_cnt=0;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='1')
                ++blk_cnt;
            else
                ans+=blk_cnt;
        }
        return ans;
    }
};