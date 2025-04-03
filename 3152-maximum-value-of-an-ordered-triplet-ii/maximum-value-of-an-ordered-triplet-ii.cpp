#define ll long long
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        ll ans=0,mx=0,diff=0;
        for(ll it:nums)
        {
            ans=max(ans,diff*it);
            diff=max(diff,mx-it);
            mx=max(mx,it);
        }
        return ans;
    }
};