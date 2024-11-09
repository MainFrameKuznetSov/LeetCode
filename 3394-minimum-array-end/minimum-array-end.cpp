class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans=x,rem=n-1,pos=1;
        while(rem)
        {
            if((x&pos)==0)
            {
                ans|=(rem&1)*pos;
                rem=rem>>1;
            }
            pos=pos<<1;
        }
        return ans;
    }
};