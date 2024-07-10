class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans=0;
        for(auto iter:logs)
        {
            if(iter=="../")
            {
                if(ans>0)
                    --ans;
            }
            else if(iter!="./")
                ++ans;
        }
        return ans;
    }
};