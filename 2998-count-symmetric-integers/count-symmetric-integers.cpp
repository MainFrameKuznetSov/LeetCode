class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;++i)
        {
            string s=to_string(i);
            int n=s.size();
            if(n&1)
                continue;
            int temp=0;
            for(int j=0;j*2<n;++j)
                temp+=(s[j]-'0')-(s[n-j-1]-'0');
            if(temp==0)
                ++ans;
        }
        return ans;
    }
};