class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size(),penalty=0,mn=0,ans=0;
        for(int i=0;i<n;++i)
        {
            if(customers[i]=='Y')
                --penalty;
            else
                ++penalty;
            if(mn>penalty)
            {
                mn=penalty;
                ans=i+1;
            }
        }
        return ans;
    }
};