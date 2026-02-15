class Solution {
public:

    string addExtraZeros(string s,int count)
    {
        string extra(count,'0');
        extra+=s;
        return extra;
    }

    string addBinary(string a, string b) {
        int n=a.size(),m=b.size();
        if(n>m)
        {
            b=addExtraZeros(b,n-m);
            m=n;
        }
        else
        {
            a=addExtraZeros(a,m-n);
            n=m;
        }
        string ans="";
        int carry=0;
        for(int i=n-1;i>=0;--i)
        {
            int sum=(a[i]-'0')+(b[i]-'0')+carry;
            carry=sum/2;
            sum=sum%2;
            ans=to_string(sum)+ans;
        }   
        if(carry)
            ans=to_string(carry)+ans;
        return ans;
    }
};