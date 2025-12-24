class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(),capacity.rend());
        int sum=0,ans=0;
        for(int i:apple)
            sum+=i;
        while(sum>0)
            sum-=capacity[ans++];
            
        return ans;
    }
};