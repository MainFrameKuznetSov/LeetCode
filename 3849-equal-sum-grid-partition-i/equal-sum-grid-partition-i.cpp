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
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        ll sum=0;
        vll rsum(n,0),csum(m,0);
        rep(i,n)
        {
            rep(j,m)
            {
                int ele=grid[i][j];
                sum+=ele;
                rsum[i]+=ele;
                csum[j]+=ele;
            }
        }
        if(sum&1)
            return 0;
        ll temp=0;
        rep(i,m-1)
        {
            temp+=csum[i];
            if(temp*2==sum)
                return 1;
        }
        
        temp=0;

        rep(i,n-1)
        {
            temp+=rsum[i];
            if(temp*2==sum)
                return 1;
        }
        return 0;
    }
};