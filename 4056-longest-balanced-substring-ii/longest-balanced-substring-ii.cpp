#define pipi pair<int,pair<int,int>>
#define F first
#define S second
#define lim 23

struct custHash
{
    size_t operator()(const pipi &x)const
    {
        size_t hsh=0;
        hsh=hsh*lim+x.F;        
        hsh=hsh*lim+x.S.F;      
        hsh=hsh*lim+x.S.S;      
        return hsh;
    }
};

class Solution{
public:
    int longestBalanced(string s){
        int n=s.size();
        if(n==1)
            return n;
        int c1=0,c2=0,c3=0,ans=0;
        unordered_map<pipi,int,custHash>m1,m2,m3,m4;
        m1[{0,{0,0}}]=m2[{0,{0,0}}]=m3[{0,{0,0}}]=m4[{0,{0,0}}]=-1;
        for(int i=0;i<n;++i)
        {
            if(s[i]=='a')
                ++c1;
            else if(s[i]=='b')
                ++c2;
            else if(s[i]=='c')
                ++c3;
            int mn=min({c1,c2,c3});
            pipi k1={c1-mn,{c2-mn,c3-mn}};
            if(m1.count(k1))
                ans=max(ans,i-m1[k1]);
            else 
                m1[k1]=i;
            int m=min(c1,c2);
            pipi k2={c1-m,{c2-m,c3}};
            if(m2.count(k2))
                ans=max(ans,i-m2[k2]);
            else 
                m2[k2]=i;
            m=min(c2,c3);
            pipi k3={c1,{c2-m,c3-m}};
            if(m3.count(k3))
                ans=max(ans,i-m3[k3]);
            else 
                m3[k3]=i;
            m=min(c3,c1);
            pipi k4={c1-m,{c2,c3-m}};
            if(m4.count(k4))
                ans=max(ans,i-m4[k4]);
            else 
                m4[k4]=i;
        }

        for(int i=1,mx=1;i<n;++i)
        {
            if(s[i]==s[i-1])
                ++mx;
            else 
                mx=1;
            ans=max(ans,mx);
        }
        return ans;
    }
};
