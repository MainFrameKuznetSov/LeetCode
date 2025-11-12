#define ll long long

class Solution {
public:

    ll helper(ll mid,vector<int>&piles)
    {
        ll sum=0;
        for(ll i:piles)
            sum+=(i+mid-1)/mid;
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        ll r=0;
        for(ll i:piles)
            r+=i;
        ll l=1;
        while(l<=r)
        {
            ll mid=l+(r-l)/2;
            if(helper(mid,piles)<=h)
                r=mid-1;
            else
                l=mid+1;
        }
        return l;
    }
};