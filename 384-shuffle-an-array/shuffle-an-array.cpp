class Solution {
public:
    vector<int>curr,original;
    Solution(vector<int>& nums) {
        this->curr=nums;
        this->original=nums;
    }
    
    vector<int> reset() {
        return original;
    }
    
    vector<int> shuffle() {
        int n=curr.size();
        for(int i=0;i<n;++i)
        {
            int randomNum=rand()%n;
            swap(curr[i],curr[randomNum]);
        }
        return curr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */