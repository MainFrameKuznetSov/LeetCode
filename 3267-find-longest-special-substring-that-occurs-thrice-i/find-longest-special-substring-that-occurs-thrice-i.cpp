class Solution {
public:
    bool solve(string &s,int n,int k)
    {
        vector<int>frq(26,0);
        int ind=0;
        for(int i=0;i<n;++i)
        {
            while(s[ind]!=s[i])
                ++ind;
            if(i+1-ind>=k)
                ++frq[s[i]-'a'];
            if(frq[s[i]-'a']>2)
                return 1;
        }
        return 0;
    }
    int maximumLength(string s) {
        int n=s.size(),l=1,r=n;
        if(!solve(s,n,l))
            return -1;
        while(l<r-1)
        {
            int mid=l+(r-l)/2;
            if(solve(s,n,mid))
                l=mid;
            else
                r=mid;
        }
        return l;
    }
};