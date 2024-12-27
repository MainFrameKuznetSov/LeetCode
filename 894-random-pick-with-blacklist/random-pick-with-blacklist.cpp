class Solution {
public:

    vector<int>v;
    int s;

    Solution(int n, vector<int>& blacklist) {
        n=min(100000,n);
        set<int>st(blacklist.begin(),blacklist.end());
        for(int i=0;i<n;++i)
        {
            if(st.find(i)==st.end())
                v.push_back(i);
        }
        s=v.size();
    }
    
    int pick() {
        int ind=rand()%s;
        return v[ind];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */