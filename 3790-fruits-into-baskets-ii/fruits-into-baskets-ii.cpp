class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans=0,n=fruits.size(),m=baskets.size();
        for(int i=0;i<n;++i)
        {
            bool f=0;
            for(int j=0;j<m;++j)
            {
                if(baskets[j]>=fruits[i])
                {
                    baskets[j]=-1;
                    f=1;
                    break;
                }
            }
            if(!f)
                ++ans;
        }
        return ans;
    }
};