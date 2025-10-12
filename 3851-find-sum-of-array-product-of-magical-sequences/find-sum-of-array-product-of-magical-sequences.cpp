#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define MOD 1000000007
#define pb push_back
#define F first
#define S second
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=(n)-1;i>=0;--i)
#define lloop(i,a,b) for(int i=(a);i<=(b);++i)
#define jloop(i,a,b,k) for(int i=(a);i<=(b);i+=(k))
#define nlloop(i,a,b) for(int i=(a);i>=(b);--i)
#define njloop(i,a,b,k) for(int i=(a);i>=(b);i-=(k))
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpii vector<pair<int,int>>
#define vpll vector<pll>
#define vvi vector<vi>
#define vb vector<bool>
#define umii unordered_map<int,int>
#define umci unordered_map<char,int>
#define umli unordered_map<ll,int>

class Solution {

private:

    ll modPow(ll x,ll y,ll p) 
    { 
        ll res=1;
        x=x%p;   
        if(x==0) 
            return 0;
        while(y>0) 
        { 
            if(y&1) 
                res=(res*x)%p; 
            y=y>>1;
            x=(x*x)%p; 
        } 
        return res; 
    }

    int setcnt(int x)
    {
        return __builtin_popcount(x);
    }

    void invfact(int n,vll &revf,ll f)
    {
        revf[n]=modPow(f,MOD-2,MOD);
        nlloop(i,n,1)
            revf[i-1]=(revf[i]*i)%MOD;
    }
    
public:
    int magicalSum(int M, int K, vector<int>& nums) {
        int n=nums.size();
        ll f=1LL;
        vll revf(M+1,1);
        lloop(i,1,M)
            f=(f*i)%MOD;
        invfact(M,revf,f);
        vector<vll>prod(n,vll(M+1,1));
        rep(i,n)
        {
            lloop(j,1,M)
                prod[i][j]=(modPow(nums[i],j,MOD)*revf[j])%MOD;;
        }
        ll dp[2][31][31][31];
        memset(dp,0,sizeof(dp));
        dp[0][0][0][0]=1;
        rep(i,n)
        {
            int par=i&1,curr=par^1;
            memset(dp[curr],0,sizeof(dp[curr]));
            lloop(j,0,M)
            {
                lloop(k,0,K)
                {
                    lloop(l,0,M)
                    {
                        ll pre=dp[par][j][k][l];
                        if(pre==0)
                            continue;
                        lloop(m,0,M-j)
                        {
                            int sum=m+l,lsb=sum&1,rem=sum>>1,extra=k+lsb;
                            if(extra>K)
                                break;
                            ll temp=(pre*prod[i][m])%MOD;
                            dp[curr][m+j][extra][rem]=(dp[curr][m+j][extra][rem]+temp)%MOD;
                        }
                    }
                }
            }
        }
        ll ans=0;
        int lsb=n&1;
        lloop(i,0,M)
        {
            int scnt=setcnt(i),rem=K-scnt;
            if(scnt>K)
                continue;
            ans=(ans+dp[lsb][M][rem][i])%MOD;
        }
        ans=(ans*f)%MOD;
        return int(ans%MOD);
    }
};