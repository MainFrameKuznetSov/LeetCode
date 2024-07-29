class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n=rating.size();
        vector<int>less(n,0),more(n,0);
        for(int i=0;i<n;++i)
        {
            for(int j=i-1;j>= 0;--j)
            {
                if(rating[i]>rating[j]) 
                    ++less[i];
                if(rating[i]<rating[j]) 
                    ++more[i];
            }
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            for(int j=i-1;j>=0;--j)
            {
                if(rating[i]>rating[j]) 
                    ans+=less[j];
                if(rating[i]<rating[j]) 
                    ans+=more[j];
            }
        }
        return ans;
    }
};