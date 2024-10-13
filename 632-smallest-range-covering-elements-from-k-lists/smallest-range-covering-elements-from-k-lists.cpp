class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int mx=INT_MIN;
        for(int i=0;i<nums.size();++i)
        {
            pq.push({nums[i][0],i,0});
            mx=max(mx,nums[i][0]);
        }
        vector<int>ans={0,INT_MAX};
        while(!pq.empty())
        {
            auto iter=pq.top();
            pq.pop();
            int mn=iter[0],ind=iter[1],ele=iter[2];
            if(mx-mn<ans[1]-ans[0] || mx-mn==ans[1]-ans[0] && mn<ans[0])
            {
                ans[0]=mn;
                ans[1]=mx;
            }
            if(ele+1<nums[ind].size())
            {
                int next=nums[ind][ele+1];
                pq.push({next,ind,ele+1});
                mx=max(mx,next);
            }
            else
                break;
        }
        return ans;
    }
};