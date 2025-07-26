#define ll long long

class Solution {
public:

    ll helper(vector<int>&bloomDay,ll mid,int k)
    {
        ll cnt=0,bqt=0;
        for(int i:bloomDay)
        {
            if(i<=mid)
                ++cnt;
            else
            {
                bqt+=(cnt/k);
                cnt=0;
            }
        }
        bqt+=(cnt/k);
        return bqt;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        ll l=INT_MAX,r=0,ans=-1;
        for(ll i:bloomDay)
        {
            l=min(l,i);
            r=max(r,i);
        }
        while(l<=r)
        {
            ll mid=l+(r-l)/2;
            if(helper(bloomDay,mid,k)>=m)
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};