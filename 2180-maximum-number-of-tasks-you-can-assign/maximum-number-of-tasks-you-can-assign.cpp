class Solution {
public:
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int n=tasks.size(),m=workers.size();
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end());
        int l=0,h=min(m,n),ans;
        while(l<=h)
        {
            int mid=l+(h-l)/2,cnt=0;
            bool f=1;
            multiset<int>st(workers.begin(),workers.end());
            for(int i=mid-1;i>=0;--i)
            {
                auto it=prev(st.end());
                if(tasks[i]<=*it)
                    st.erase(it);
                else
                {
                    auto it=st.lower_bound(tasks[i]-strength);
                    if(it!=st.end())
                    {
                        ++cnt;
                        st.erase(it);
                    }
                    else
                    {
                        f=0;
                        break;
                    }
                }
                if(cnt>pills)
                {
                    f=0;
                    break;
                }
            }
            if(f)
            {
                ans=mid;
                l=mid+1;
            }
            else
                h=mid-1;
        }
        return ans;
    }
};