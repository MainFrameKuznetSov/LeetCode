class Solution {
public:
    int largestPalindrome(int n) {
        if(n==1)
            return 9;
        int right=pow(10,n)-1,left=pow(10,n-1),MOD=1337;
        for(int i=right;i>=left;--i)
        {
            string val=to_string(i),temp=val;
            reverse(temp.begin(),temp.end());
            val+=temp;
            long long num=stoll(val);
            for(int j=right;j>=sqrtl(num);--j)
            {
                if(num%j==0)
                    return num%MOD;
            }
        }
        return 0;
    }
};