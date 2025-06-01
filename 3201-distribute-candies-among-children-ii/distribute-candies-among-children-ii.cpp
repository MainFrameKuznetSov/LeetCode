class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans=0;
        for(int i=max(0,n-2*limit);i<=min(limit,n);++i)
        {
            int temp=min(limit,n-i)-max(0,n-i-limit);
            ans+=max(0,temp+1);
        }
        return ans;
    }
};