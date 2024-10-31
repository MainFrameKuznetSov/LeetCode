class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(),robot.end());
        sort(factory.begin(),factory.end());
        int m=robot.size(),n=factory.size();
        vector<vector<long long>>dp(m+1,vector<long long>(n+1));
        for(int i=0;i<m;++i)
            dp[i][n]=LLONG_MAX;        
        for(int j=n-1;j>=0;--j) 
        {
            long long prefix=0;
            deque<pair<int,long long>>dq;
            dq.push_back({m,0});
            for(int i=m-1;i>=0;--i) 
            {
                prefix+=abs(robot[i]-factory[j][0]);
                
                while(!dq.empty() && dq.front().first>i+factory[j][1])
                    dq.pop_front();
                
                while(!dq.empty() && dq.back().second>=dp[i][j+1]-prefix)
                    dq.pop_back();
                
                dq.push_back({i,dp[i][j+1]-prefix});
                dp[i][j]=dq.front().second+prefix;
            }
        }
        return dp[0][0];
    }
};