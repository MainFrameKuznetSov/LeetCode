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
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        vi ans(n,-1),res;
        unordered_map<int,vi>mp;
        rep(i,n)
            mp[nums[i]].pb(i);
        for(auto it:mp)
        {
            vi temp=it.S;
            int sz=temp.size();
            if(sz<2)
                continue;
            sort(all(temp));
            rep(j,sz)
            {
                int now=temp[j],pre=temp[(j+sz-1)%sz],nex=temp[(j+1)%sz];
                int ldiff=abs(pre-now),rdiff=abs(nex-now);
                ldiff=min(ldiff,n-ldiff);
                rdiff=min(rdiff,n-rdiff);
                ans[now]=min(ldiff,rdiff);
            }
        }
        for(int i:queries)
            res.pb(ans[i]);
        return res;
    }
};