class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n=points.size();
        unordered_map<float,vector<float>>s2i;
        unordered_map<int,vector<float>>m2s;

        int res=0;

        for(int i=0;i<n;++i) 
        {
            for(int j=i+1;j<n;++j) 
            {
                int x1=points[i][0],y1=points[i][1],x2=points[j][0],y2=points[j][1];
                int dx=x2-x1,dy=y2-y1;
                float s,c;
                if(dx==0) 
                {
                    s=1e9+7;
                    c=x1;
                } 
                else 
                {
                    s=(float)dy/dx;
                    c=(float)(y1*dx-x1*dy)/dx;
                }

                int mk=(x1+x2)*10000+(y1+y2);
                s2i[s].push_back(c);
                m2s[mk].push_back(s);
            }
        }

        for(auto &e:s2i) 
        {
            if(e.second.size()<=1) 
                continue;

            map<float,int>m;
            for(float c:e.second) 
                ++m[c];

            int prev=0;
            for(auto &p:m) 
            {
                int cnt=p.second;
                res+=cnt*prev;
                prev+=cnt;
            }
        }

        for(auto &e:m2s) 
        {
            if(e.second.size()<=1) 
                continue;

            map<float,int>m;
            for(float s:e.second) 
                ++m[s];

            int prev=0;
            for(auto &p:m) 
            {
                int cnt=p.second;
                res-=cnt*prev;
                prev+=cnt;
            }
        }
        return res;
    }
};