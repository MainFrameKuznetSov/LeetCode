#define MOD 1000000007

class Solution {
public:
    int numSub(string s) {
        int cnt=0,ans=0;
        for(char c:s)
        {
            if(c=='1')
                ++cnt;
            else
                cnt=0;
            ans=(ans+cnt)%MOD;
        }
        return ans;
    }
};