#define ll long long

class Solution{
    multiset<ll> leftSet,rightSet;
public:
    long long minimumCost(vector<int>& nums,int k,int dist){
        int n=nums.size();
        --k;
        ll sum=nums[0];

        for(int i=1;i<=dist+1;i++)
        {
            sum+=nums[i];
            leftSet.insert(nums[i]);
        }

        while(leftSet.size()>k)
        {
            auto it=prev(leftSet.end());
            sum-=*it;
            rightSet.insert(*it);
            leftSet.erase(it);
        }

        ll ans=sum;

        for(int i=dist+2;i<n;i++)
        {
            int out=nums[i-dist-1];
            auto itL=leftSet.find(out);
            if(itL!=leftSet.end())
            {
                sum-=out;
                leftSet.erase(itL);
            }
            else
                rightSet.erase(rightSet.find(out));
            if(!leftSet.empty() && nums[i]<*prev(leftSet.end()))
            {
                sum+=nums[i];
                leftSet.insert(nums[i]);
            }
            else
                rightSet.insert(nums[i]);
            while(leftSet.size()<k)
            {
                auto it=rightSet.begin();
                sum+=*it;
                leftSet.insert(*it);
                rightSet.erase(it);
            }
            while(leftSet.size()>k)
            {
                auto it=prev(leftSet.end());
                sum-=*it;
                rightSet.insert(*it);
                leftSet.erase(it);
            }
            ans=min(ans,sum);
        }
        return ans;
    }
};
