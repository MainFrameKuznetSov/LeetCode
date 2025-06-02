class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>val(n,1);
        for(int i=0;i<n-1;i++)
        {
            if(ratings[i+1]>ratings[i])
                val[i+1]=max(val[i]+1,val[i+1]);
            if(ratings[n-i-2]>ratings[n-i-1])
                val[n-i-2]=max(val[n-i-1]+1,val[n-i-2]);
        }
        int sum=0;
        for(int i=0;i<n;i++)
            sum+=val[i];
        return sum;
    }
};