class Solution {
public:
    int climbStairs(int n) {
        int fst=1,sec=1;
        int ans=1;
        for(int i=2;i<=n;++i)
        {
            ans=fst+sec;
            fst=sec;
            sec=ans;
        }
        return ans;
    }
};