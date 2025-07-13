class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int ans=0,l=0,r=0,m=players.size(),n=trainers.size();
        while(l<m && r<n)
        {
            if(players[l]<=trainers[r])
            {
                ++ans;
                ++l;
                ++r;
            }
            else
                ++r;
        }
        return ans;
    }
};