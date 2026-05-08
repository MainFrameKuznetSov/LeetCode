class Solution {
public:
    int minJumps(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int n=nums.size();
        for(int i=0;i<n;++i) 
        {
            int tmp=nums[i];
            for(int d=2;d*d<=tmp;++d) 
            {
                if(tmp%d==0) 
                {
                    mp[d].push_back(i);
                    while(tmp%d==0) 
                        tmp/=d;
                }
            }
            if(tmp>1)
                mp[tmp].push_back(i);
        }
        vector<bool>vis(n,false);
        queue<int>q;
        q.push(0);
        int ans=0;
        while(!q.empty()) 
        {
            int sz=q.size();
            while(sz--) 
            {
                int i=q.front(),num=nums[i];
                q.pop();
                if(vis[i]) 
                    continue;
                vis[i]=true;
                if(i+1==n) 
                    return ans;
                if(mp.count(num)) 
                {
                    for(int node:mp[num]) 
                        q.push(node);
                    mp.erase(num);
                }
                if(i+1<n)
                    q.push(i+1);
                if(i-1>=0)
                    q.push(i-1);
            }
            ++ans;
        }
        return ans;
    }
};