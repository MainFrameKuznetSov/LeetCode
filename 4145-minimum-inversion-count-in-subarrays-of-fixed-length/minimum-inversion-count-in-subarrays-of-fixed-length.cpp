#define ll long long

class Tree
{
    public:
        int n;
        vector<int>frq;
        Tree(int n=0):n(n),frq(n+1,0){}

        void push(int i,int diff)
        {
            while(i<=n)
            {
                frq[i]+=diff;
                i+=(i&-i);
            }
        }

        int getSum(int i)
        {
            int end=0;
            while(i>0)
            {
                end+=frq[i];
                i-=(i&-i);
            }
            return end;
        }
        
};

class Solution {
public:    
    long long minInversionCount(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==1)
            return 0;
        set<int>st(nums.begin(),nums.end());
        vector<int>cpy(st.begin(),st.end());
        st.clear();
        int sz=cpy.size();
        vector<int>v(n);
        for(int i=0;i<n;++i)
            v[i]=1+int(lower_bound(cpy.begin(),cpy.end(),nums[i])-cpy.begin());
        Tree tree(sz);
        ll temp=0;
        for(int i=0;i<k;++i)
        {
            temp+=(ll)i-tree.getSum(v[i]);
            tree.push(v[i],1);
        }
        ll ans=temp;
        for(int i=0;i<n-k;++i)
        {
            int opt=v[i];
            ll left=tree.getSum(opt-1);
            temp-=left;
            tree.push(opt,-1);
            int inp=v[i+k];
            ll right=(ll)(k-1)-tree.getSum(inp);
            temp+=right;
            tree.push(inp,1);
            ans=min(ans,temp);
        }
        return ans;
    }
};