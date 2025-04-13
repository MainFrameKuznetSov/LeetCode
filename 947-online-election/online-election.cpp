class TopVotedCandidate {
public:

    vector<int>ans,time;

    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        time=times;
        int n=persons.size();
        unordered_map<int,int>mp;
        int temp=-1,mx=0;
        for(int i=0;i<n;++i)
        {
            ++mp[persons[i]];
            if(mp[persons[i]]>=mx)
            {
                mx=mp[persons[i]];
                temp=persons[i];
            }
            ans.push_back(temp);
        }
    }
    
    int q(int t) {
        int ind=upper_bound(time.begin(),time.end(),t)-time.begin();
        return ans[ind-1];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */