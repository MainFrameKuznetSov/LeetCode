#define ll long long

class Solution {
public:

    ll helper(int mid,vector<int>&bloomDay,int k)
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
        ll l=INT_MAX,r=INT_MIN,ans=-1;
        int n=bloomDay.size();
        // if(n<(m*k))
        //     return -1;
        for(ll i:bloomDay)
        {
            l=min(l,i);
            r=max(r,i);
        }
        while(l<=r)
        {
            ll mid=l+(r-l)/2;
            if(helper(mid,bloomDay,k)>=m)
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