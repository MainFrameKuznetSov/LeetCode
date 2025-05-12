class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>ans,cnt(10,0);
        for(int i:digits)
            ++cnt[i];
        for(int i=100;i<999;i+=2)
        {
             int hun=i/100,tens=i/10%10,one=i%10;
             bool chk=(--cnt[hun]>=0 & --cnt[tens]>=0 & --cnt[one]>=0);
             if(chk)
                ans.push_back(i);
            ++cnt[hun];
            ++cnt[tens];
            ++cnt[one];
        }
        return ans;
    }
};