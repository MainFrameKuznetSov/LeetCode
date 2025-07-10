class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int>temp;
        temp.push_back(startTime[0]);
        int n=startTime.size();
        for(int i=1;i<n;++i)
            temp.push_back(startTime[i]-endTime[i-1]);
        temp.push_back(eventTime-endTime[n-1]);
        vector<int>rgap(temp.size(),0);
        for(int i=temp.size()-2;i>=0;--i)
            rgap[i]=max(rgap[i+1],temp[i+1]);
        int ans=0,l=0;
        for(int i=1;i<temp.size();++i)
        {
            int curr=endTime[i-1]-startTime[i-1];
            if(curr<=max(l,rgap[i]))
                ans=max(ans,temp[i-1]+temp[i]+curr);
            ans=max(ans,temp[i-1]+temp[i]);
            l=max(l,temp[i-1]);
        }
        return ans;
    }
};