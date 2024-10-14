class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int,vector<int>>pq;
        for(int i=0;i<nums.size();++i)
            pq.push(nums[i]);
        long long score=0;
        while(k--)
        {
            int temp=pq.top();
            score+=temp;
            pq.pop();
            int newVal=(temp%3==0)?temp/3:temp/3+1;
            /*if(temp%3==0)
                newVal=temp/3;
            else
                newVal=temp/3+1;*/
            pq.push(newVal);
        }
        return score;
    }
};