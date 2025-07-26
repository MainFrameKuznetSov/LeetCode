#define ll long long

class Solution {
public:

    long long helper(vector<int>&piles,long long mid)
    {
        ll sum=0;
        for(ll i:piles)
            sum+=(i+mid-1)/mid;
        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long l=1,r=0;
        for(long long i:piles)
            r=max(r,i);
        while(l<=r)
        {
            ll mid=l+(r-l)/2;
            if(helper(piles,mid)<=h)
                r=mid-1;
            else
                l=mid+1;
        }
        return l;
    }
};