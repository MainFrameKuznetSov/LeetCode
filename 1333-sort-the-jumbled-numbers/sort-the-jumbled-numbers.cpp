class Solution {
public:
    typedef pair<int,int>p;
    vector<int> sortJumbled(vector<int>& mp, vector<int>& nums) {
        priority_queue<p,vector<p>,greater<p>>minHeap;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int mapNum=0,curr=nums[i],tens=1;
            if(curr==0)
                mapNum=mp[0];
            while(curr)
            {
                int idx=curr%10;
                curr/=10;
                mapNum+=tens*mp[idx];
                tens*=10;
            }
            minHeap.push({mapNum,i});
        }
        vector<int>ans;
        while(!minHeap.empty())
        {
            int num=nums[minHeap.top().second];
            ans.push_back(num);
            minHeap.pop();
        }
        return ans;
    }
};