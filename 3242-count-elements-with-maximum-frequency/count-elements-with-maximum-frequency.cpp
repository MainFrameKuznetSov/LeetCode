class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int>freq(101,0);
        int maxFreq=0,ans=0;
        for(int i:nums)
        {
            ++freq[i];
            if(freq[i]>maxFreq)
            {
                maxFreq=freq[i];
                ans=freq[i];
            }
            else if(freq[i]==maxFreq)
                ans+=freq[i];
        }
        return ans;
    }
};