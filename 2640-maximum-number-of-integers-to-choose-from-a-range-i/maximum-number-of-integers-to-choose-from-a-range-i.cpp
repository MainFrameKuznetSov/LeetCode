class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int>st(banned.begin(),banned.end());
        long long sum=0,ans=0;
        for(int i=1;i<=n;++i)
        {
            if(st.find(i)!=st.end())
                continue;
            sum+=i;
            if(sum>maxSum)
                break;
            ++ans;
        }
        return ans;
    }
};