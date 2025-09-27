class Solution {
public:

    double distance(vector<int>&x,vector<int>&y,vector<int>&z)
    {
        return 0.5*abs(x[0]*(y[1]-z[1])+y[0]*(z[1]-x[1])+z[0]*(x[1]-y[1]));
    }

    double largestTriangleArea(vector<vector<int>>& v) {
        double maxArea=0.0;
        int n=v.size();
        for(int i=0;i<n-2;++i)
        {
            for(int j=i+1;j<n-1;++j)
            {
                for(int k=j+1;k<n;++k)
                    maxArea=max(maxArea,distance(v[i],v[j],v[k]));
            }
        }
        return maxArea;
    }
};