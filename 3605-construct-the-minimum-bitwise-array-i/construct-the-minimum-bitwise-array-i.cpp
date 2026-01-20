class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>ans;
        for(int i:nums)
        {
            int temp=-1,det=1;
            while(i&det)
            {
                temp=i-det;
                det<<=1;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};