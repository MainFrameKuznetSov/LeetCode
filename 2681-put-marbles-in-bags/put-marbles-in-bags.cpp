class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n=weights.size();
        vector<int>v;
        for(int i=1;i<n;++i)
            v.push_back(weights[i-1]+weights[i]);
        sort(v.begin(),v.end());
        long long mn=0,mx=0;
        for(int i=0;i<k-1;++i)
            mn+=v[i];
        for(int i=n-2;i>=n-k;--i)
            mx+=v[i];
        return (mx-mn);
    }
};