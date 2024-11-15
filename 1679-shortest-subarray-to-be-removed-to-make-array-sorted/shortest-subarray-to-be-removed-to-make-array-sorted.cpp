class Solution {
public:
    static int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size(),l=0,r=n-1;
        while(l<n-1 && arr[l]<=arr[l+1])
            ++l;
        if(l==n-1)
            return 0;
        while(l<r && arr[r-1]<=arr[r])
            --r;
        int ans=min(r,n-l-1);
        for(int i=0,j=r;i<=l && j<n;)
        {
            if(arr[j]>=arr[i])
                ans=min(ans,j-1-i++);
            else
                ++j;
        }
        return ans;
    }
};

