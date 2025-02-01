class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 1;
        if(n==2)
            return (nums[0]%2!=nums[1]%2);
        for(int i=1;i<n-1;++i)
        {
            int parleft=nums[i-1]%2;
            int parright=nums[i+1]%2;
            if(parleft==nums[i]%2 || parright==nums[i]%2)
                return 0;
        }
        return 1;
    }
};