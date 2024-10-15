class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0,cnt=0;
        for(char ch:s)
        {
            if(ch=='1')
                ++cnt;
            else
                ans+=cnt;
        }
        return ans;
    }
};