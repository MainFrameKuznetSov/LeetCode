class Solution {
public:
    int maxDistance(string s, int k) {
        int cN=0,cS=0,cE=0,cW=0,x=0,y=0,ans=0;
        for(char ch:s)
        {
            if(ch=='N')
            {
                ++cN;
                ++y;
            }
            else if(ch=='E')
            {
                ++cE;
                ++x;
            }
            else if(ch=='S')
            {
                ++cS;
                --y;
            }
            else
            {
                ++cW;
                --x;
            }
            int curr=abs(x)+abs(y),tk=k;
            if(cS>cN && tk)
            {
                curr+=min(tk,cN)*2;
                tk-=min(tk,cN);
            }
            if(cN>=cS && tk)
            {
                curr+=min(tk,cS)*2;
                tk-=min(tk,cS);
            }
            if(cW>cE && tk)
            {
                curr+=min(tk,cE)*2;
                tk-=min(k,cE);
            }
            if(cE>=cW && tk)
            {
                curr+=min(tk,cW)*2;
                tk-=min(tk,cW);
            }
            ans=max(ans,curr);
        }
        return max(ans,abs(x)+abs(y));
    }
};