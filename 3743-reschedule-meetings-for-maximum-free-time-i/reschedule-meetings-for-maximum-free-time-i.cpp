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
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size(),slide=0,ans;
        vi psum;
        psum.pb(startTime[0]);
        lloop(i,1,n-1)
            psum.pb(startTime[i]-endTime[i-1]);
        psum.pb(eventTime-endTime[n-1]);
        rep(i,k+1)
            slide+=psum[i];
        ans=slide;
        lloop(i,k+1,(int)psum.size()-1)
        {
            slide+=psum[i]-psum[i-k-1];
            ans=max(ans,slide);
        }
        return ans;
    }
};