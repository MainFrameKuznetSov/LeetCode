class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int>start,end;
        for(auto iter:intervals)
        {
            start.push_back(iter[0]);
            end.push_back(iter[1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int right=0,ans=0;
        for(int iter:start)
        {
            if(iter>end[right])
                ++right;
            else
                ++ans;
        }
        return ans;
    }
};