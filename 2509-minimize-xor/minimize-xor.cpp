class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int res=num1,cnt1=__builtin_popcount(num1),cnt2=__builtin_popcount(num2);
        int ptr=0;
        while(cnt1<cnt2)
        {
            if(!(res&(1<<ptr)))
            {
                res|=(1<<ptr);
                ++cnt1;
            }
            ++ptr;
        }

        while(cnt1>cnt2)
        {
            if(res & (1<<ptr))
            {
                res&=~(1<<ptr);
                --cnt1;
            }
            ++ptr;
        }

        return res;
    }
};