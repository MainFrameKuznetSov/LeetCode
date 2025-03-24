class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int ans=meetings[0][0]-1,n=meetings.size(),maxR=meetings[0][1];
        for(int i=1;i<n;++i)
        {
            int preL=meetings[i-1][0],preR=meetings[i-1][1];
            //cout<<preL<<" "<<preR<<"\n";
            int curL=meetings[i][0],curR=meetings[i][1];
            //cout<<preL<<" "<<preR<<"|||"<<curL<<" "<<curR<<"-->";
            if(curL>maxR)
                ans+=(curL-maxR-1);
            //cout<<ans<<"\n";       
            maxR=max(maxR,max(curR,preR));     
        }
        //if(days!=meetings[n-1][1])
        ans+=max(days-maxR,0);
        return ans;
    }
};