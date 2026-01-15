class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int mxH=1,mxV=1,mx=1;

        for(int i=1;i<hBars.size();++i) 
        {
            if(hBars[i]==hBars[i-1]+1)
                ++mx;
            else 
            {
                mxH=max(mxH,mx);
                mx=1;
            }
        }
        mxH=max(mxH,mx);
        mx=1;

        for(int i=1;i<vBars.size();++i) 
        {
            if(vBars[i]==vBars[i-1]+1)
                ++mx;
            else 
            {
                mxV=max(mxV,mx);
                mx=1;
            }
        }
        mxV=max(mxV,mx);
        int side=min(mxH+1,mxV+1);
        return (side*side);
    }
};