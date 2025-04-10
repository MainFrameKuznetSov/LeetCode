class NumArray {
public:

    vector<long long>psum;

    NumArray(vector<int>& nums) {
        int n=nums.size();
        psum.resize(n+1,0);
        for(int i=0;i<n;++i)
            psum[i+1]=(long long)psum[i]+nums[i];
    }
    
    int sumRange(int left, int right) {
        /*
            [1,2,3,4]
            [0,1,3,6,10]
        */
        return psum[right+1]-psum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */