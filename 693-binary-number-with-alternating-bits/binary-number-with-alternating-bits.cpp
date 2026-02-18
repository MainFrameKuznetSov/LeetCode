class Solution {
public:
    bool hasAlternatingBits(int n) {
        int pre=n&1;
        n>>=1;
        while(n)
        {
            int cur=n&1;
            n>>=1;
            if(pre==cur)
                return false;
            pre=cur;
        }
        return true;
    }
};