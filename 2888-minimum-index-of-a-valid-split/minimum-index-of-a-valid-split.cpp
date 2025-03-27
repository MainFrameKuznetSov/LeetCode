class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>freq;
        int most=0,cnt=0,n=nums.size();
        for(int i:nums)
            ++freq[i];
        for(auto it:freq)
        {
            if(it.second*2>n)
            {
                most=it.first;
                cnt=it.second;
                break;
            }
        }
        int fp=0;
        for(int i=0;i<n-1;++i)
        {
            if(nums[i]==most)
                ++fp;
            int fsize=i+1,lsize=n-fsize,rcnt=cnt-fp;
            if(fp*2>fsize && rcnt*2>lsize)
                return i;
        }
        return -1;
    }
};