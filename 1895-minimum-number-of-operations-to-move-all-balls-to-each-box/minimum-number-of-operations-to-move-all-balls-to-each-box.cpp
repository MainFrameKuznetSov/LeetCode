class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>ans(n,0);
        int lb=0,lm=0,rb=0,rm=0;
        for(int i=0;i<n;++i)
        {
            ans[i]+=lm;
            lb+=(boxes[i]-'0');
            lm+=lb;
            ans[n-i-1]+=rm;
            rb+=(boxes[n-i-1]-'0');
            rm+=rb;
        }
        return ans;
    }
};