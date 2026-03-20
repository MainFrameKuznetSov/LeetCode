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
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size(),R=n-k+1,C=m-k+1;
        vvi ans(R,vi(C,0));
        lloop(i,0,n-k)
        {
            lloop(j,0,m-k)
            {
                vi temp(k*k);
                int ins=0;
                rep(ni,k)
                {
                    rep(nj,k)
                        temp[ins++]=(grid[i+ni][j+nj]);
                }
                sort(all(temp));
                set<int>st(all(temp));
                temp=vi(all(st));
                st.clear();
                if(temp.size()==1)
                    continue;
                int mn=INT_MAX;
                lloop(l,1,(int)temp.size()-1)
                {
                    int sep=temp[l]-temp[l-1];
                    if(sep<mn)
                        mn=sep;
                    if(mn==0)
                        break;
                }
                ans[i][j]=mn;
            }
        }
        return ans;
    }
};