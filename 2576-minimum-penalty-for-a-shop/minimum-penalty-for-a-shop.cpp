class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size(),penalty=0,mn=0,ans=0;
        for(int i=0;i<n;++i)
        {
            int temp;
            if(customers[i]=='Y')
                temp=1;
            else
                temp=-1;
            penalty-=temp;
            if(mn>penalty)
            {
                mn=penalty;
                ans=i+1;
            }
        }
        return ans;
    }
};