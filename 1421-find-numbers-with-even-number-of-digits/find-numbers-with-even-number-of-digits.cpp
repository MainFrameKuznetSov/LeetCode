class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0;
        for(int i:nums)
        {
            //int cnt=(int)log10(i)+1;
            if((int)log10(i)&1)
                ++ans;
        }
        return ans;
    }
};