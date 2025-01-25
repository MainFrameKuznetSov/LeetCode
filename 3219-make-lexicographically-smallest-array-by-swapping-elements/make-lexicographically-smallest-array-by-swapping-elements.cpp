class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>>pr;
        for(int i=0;i<n;++i) 
            pr.push_back({nums[i],i});
        sort(pr.begin(),pr.end());

        vector<int>ans(n);
        int grp=0;

        for(int i=0;i<n;++i) 
        {
            if(i+1==n || pr[i+1].first>limit+pr[i].first) 
            {
                vector<int>temp;
                for(int j=grp;j<=i;++j) 
                    temp.push_back(pr[j].second);
                sort(temp.begin(),temp.end());
                for(int j=0;j<temp.size();++j) 
                    ans[temp[j]]=pr[grp+j].first;
                
                grp=i+1;
            }
        }
        return ans;
    }
};