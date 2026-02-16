class Solution {
public:

    string rev(int n)
    {
        string ans="";
        while(n)
        {
            ans=to_string(n%2)+ans;
            n>>=1;
        }
        return ans;
    }

    int reverseBits(int n) {
        string revd=rev(n);
        reverse(revd.begin(),revd.end());
        revd+=string(32-(int)revd.size(),'0');
        // cout<<revd<<"\n";
        int pwr=0;
        long long ans=0;
        for(int i=revd.size()-1;i>=0;--i)
        {
            ans+=(long long)((revd[i]-'0')<<pwr);
            ++pwr;
        }
        return (int)ans;
    }
};