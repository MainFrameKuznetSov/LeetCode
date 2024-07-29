class Solution {
public:
    long long numberOfWeeks(vector<int>& milestone) {
        sort(milestone.begin(),milestone.end());
        int n=milestone.size();
        long long ans=0;
        for(int i=0;i<n-1;i++)
            ans+=milestone[i];
        if(milestone[n-1]-ans<=1)
            return milestone[n-1]+ans;
        else
            return 2*ans+1;
    }
};