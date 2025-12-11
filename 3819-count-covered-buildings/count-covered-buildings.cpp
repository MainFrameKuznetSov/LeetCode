class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int>mxR(n+1),mnR(n+1,n+1),mxC(n+1),mnC(n+1,n+1);
        for(auto it:buildings) 
        {
            int x=it[0],y=it[1];
            mxR[y]=max(mxR[y],x);
            mnR[y]=min(mnR[y],x);
            mxC[x]=max(mxC[x],y);
            mnC[x]=min(mnC[x],y);
        }

        int ans=0;
        for(auto it:buildings) 
        {
            int x=it[0],y=it[1];
            if(x>mnR[y] && x<mxR[y] && y>mnC[x] && y<mxC[x]) 
                ++ans;
        }

        return ans;
    }
};