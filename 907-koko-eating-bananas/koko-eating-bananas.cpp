#define ll long long

class Solution {
public:

    ll helper(ll mid,vector<int>&piles)
    {
        ll ans=0;
        for(ll i:piles)
            ans+=(i+mid-1)/mid;
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        ll left=1,right=piles[n-1];
        while(left<=right)
        {
            ll mid=left+(right-left)/2;
            if(helper(mid,piles)<=h)
                right=mid-1;
            else
                left=mid+1;
        }
        return left;
    }
};