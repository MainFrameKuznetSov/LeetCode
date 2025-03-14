class Solution {
public:

    bool solve(vector<int>arr,long long k,int mid)
    {
        for(int i:arr)
        {
            k-=(i/mid);
            if(k<=0)
                return 1;
        }
        return 0;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        long long sum=0;
        for(int i=0;i<n;++i)
            sum+=candies[i];
        if(sum<k)
            return 0;
        int l=1,r=sum/k;
        while(l<r)
        {
            int mid=l+(r-l+1)/2;
            if(solve(candies,k,mid))
                l=mid;
            else
                r=mid-1;
        }
        return l;
    }
};