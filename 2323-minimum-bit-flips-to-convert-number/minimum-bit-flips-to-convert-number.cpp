class Solution {
public:
    int minBitFlips(int start, int goal) {
        int temp=start^goal,ans=0;
        while(temp)
        {
            ans+=(temp&1);
            temp>>=1;
        }
        return ans;
    }
};