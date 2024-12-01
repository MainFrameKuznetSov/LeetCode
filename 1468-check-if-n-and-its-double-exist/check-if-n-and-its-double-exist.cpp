class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(int i:arr)
            ++mp[i];
        for(int i:arr)
        {
            if(mp.find(i*2)!=mp.end())
            {  
                if(i==0)
                {
                    if(mp[0]>1)
                        return 1;
                }
                else
                    return 1;
            }
        }
        return 0;
    }
};