class Solution {
public:
    long long minimumSteps(string s) {
        long long swaps=0,blk_cnt=0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='1')
                ++blk_cnt;
            else
                swaps+=blk_cnt;
        }
        return swaps;
    }
};