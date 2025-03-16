#define ll long long
class Solution {
public:

    bool solve(vector<int>v,ll n,int chk)
    {
        ll ans=0;
        for(int i:v)
        {
            ans+=sqrt(n/i);
            if(ans>=chk)
                return 1;
        }
        return 0;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        ll low=1,high=(ll)*min_element(ranks.begin(),ranks.end())*cars*cars;
        while(low<high)
        {
            ll mid=low+(high-low)/2;
            if(solve(ranks,mid,cars))
                high=mid;
            else
                low=mid+1;
        }
        return low;
    }
};