class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        for(int hours=0;hours<=11;++hours)
        {
            for(int minutes=0;minutes<=59;++minutes)
            {
                if(__builtin_popcount(hours)+__builtin_popcount(minutes)==turnedOn)
                {
                    string temp=to_string(hours)+":"+(minutes<10?"0":"")+to_string(minutes);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};