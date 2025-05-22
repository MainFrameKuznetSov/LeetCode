class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& query) {
        sort(query.begin(),query.end());
        priority_queue<int>mx;
        priority_queue<int,vector<int>,greater<int>>mn;
        int cnt=0,n=query.size();
        for(int i=0,k=0;i<nums.size();++i) 
        {
            while(!mn.empty() && mn.top()<i)
                mn.pop();
            while(k<n && query[k][0]<=i) 
                mx.push(query[k++][1]);
            while(mn.size()<nums[i] && !mx.empty() && mx.top()>=i) 
            {
                mn.push(mx.top());
                mx.pop();
                ++cnt;
            }
            if(mn.size()<nums[i])
                return -1;
        }
        return n-cnt;
    }
};