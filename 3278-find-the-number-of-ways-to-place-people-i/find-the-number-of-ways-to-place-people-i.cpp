class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size(),ans=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(i==j)
                    continue;
                int x1=points[i][0],y1=points[i][1],x2=points[j][0],y2=points[j][1];
                if(x1<=x2 && y1>=y2)
                {
                    bool flag=false;
                    for(int k=0;k<n;++k)
                    {
                        if(k==i || k==j)
                            continue;
                        int x3=points[k][0],y3=points[k][1];
                        if(x3>=x1 && x2>=x3 && y3>=y2 && y3<=y1)
                        {
                            flag=true;
                            break;
                        }
                    }
                    if(!flag)
                        ++ans;
                }
            }
        }
        return ans;
    }
};