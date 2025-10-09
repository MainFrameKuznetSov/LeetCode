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
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n=skill.size(),m=mana.size();
        vll psum(n,0),pre(n,0);
        rep(i,n-1)
            psum[i+1]=psum[i]+skill[i];
        pre[0]=(ll)(mana[0]*skill[0]);
        lloop(i,1,n-1)
            pre[i]=pre[i-1]+(ll)(mana[0]*skill[i]);
        lloop(i,1,m-1)
        {
            ll temp=pre[0];
            lloop(j,1,n-1)
            {
                ll curr=pre[j]-(ll)(mana[i]*psum[j]);
                temp=max(temp,curr);
            }
            vll cur(n,0);
            cur[0]=temp+(ll)(mana[i]*skill[0]);
            lloop(j,1,n-1)
                cur[j]=max(cur[j-1],cur[j])+(ll)(mana[i]*skill[j]);
            pre=cur;
        }
        return pre[n-1];
    }
};