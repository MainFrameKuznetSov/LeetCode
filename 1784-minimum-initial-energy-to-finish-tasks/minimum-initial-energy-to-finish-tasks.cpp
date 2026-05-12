#define ll long long

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[&](vector<int>&x,vector<int>&y) 
        {
            return(x[1]-x[0])>(y[1]-y[0]);
        });
        int n=tasks.size(); 
        ll ans=0,nrg=0;
        for(int i=0;i<n;++i) 
        {
            int real=tasks[i][0],min=tasks[i][1];
            if(nrg<min) 
            {
                ans+=(min-nrg);
                nrg=min;
            }
            nrg-=real;
        }
        return (int)ans;
    }
};