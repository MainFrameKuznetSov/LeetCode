class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size(),ans=0;
        for(int i=0;i+1<n;++i)
            ans+=max(abs(points[i+1][0]-points[i][0]),abs(points[i+1][1]-points[i][1]));
        return ans;
    }
};