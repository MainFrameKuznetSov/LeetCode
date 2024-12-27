class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans=INT_MIN,cmp=values[0];
        for(int i=1;i<values.size();++i)
        {
            if(values[i]+cmp>ans+i)
                ans=values[i]+cmp-i;
            if(values[i]+i>cmp)
                cmp=values[i]+i;
        }
        return ans;
    }
};