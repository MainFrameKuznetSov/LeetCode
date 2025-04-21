class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long tot=0,mn=0,mx=0;
        for(int i:differences)
        {
            tot+=i;
            mn=min(mn,tot);
            mx=max(mx,tot);
        }
        return max(0LL,mn-mx+upper-lower+1);

    }
};