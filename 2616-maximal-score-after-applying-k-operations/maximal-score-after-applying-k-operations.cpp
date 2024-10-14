class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int,vector<int>>pq;
        for(int it:nums)
            pq.push(it);
        long long ans=0;
        while(k)
        {
            int val=pq.top();
            ans+=val;
            pq.pop();
            int temp=val%3==0?val/3:val/3+1;
            pq.push(temp);
            //cout<<val<<" "<<temp<<"\n";
            --k;
        }
        return ans;
    }
};