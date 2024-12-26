class Solution {
public:

    set<vector<int>>st;
    bool hbe(int size,vector<int>&src,vector<int>&tar)
    {
        vector<pair<int,int>>dir={{-1,0},{0,-1},{0,1},{1,0}};
        int area=(size*size)/2,cnt=0;
        set<pair<int,int>>vis;
        queue<pair<int,int>>q;
        q.push({src[0],src[1]});
        while(!q.empty())
        {
            int r=q.front().first,c=q.front().second;
            q.pop();
            if((r==tar[0] && c==tar[1]) || (area<cnt))
                return 1;
            for(int i=0;i<4;++i)
            {
                int nr=r+dir[i].first,nc=c+dir[i].second;
                if(nr>=0 && nr<1000000 && nc>=0 && nc<1000000)
                {
                    if(vis.find({nr,nc})==vis.end() && st.find({nr,nc})==st.end())
                    {
                        q.push({nr,nc});
                        vis.insert({nr,nc});
                    }
                }
            }
            ++cnt;
        }
        return 0;
    }

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& src, vector<int>& tar) {
        for(auto i:blocked)
            st.insert(i);
        return (hbe(blocked.size(),src,tar) && hbe(blocked.size(),tar,src));
    }
};