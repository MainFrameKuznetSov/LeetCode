class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double ans=0;
        int n=customers.size();
        long long curr=customers[0][1]+customers[0][0],wait=customers[0][1];
        for(int i=1;i<n;++i)
        {
            int arr=customers[i][0],time=customers[i][1];
            int temp;
            if(arr>curr)
            {
                temp=time;
                curr=arr+time;
            }
            else
            {
                temp=(curr+time)-arr;
                curr+=time;
            }
            wait+=temp;
            //curr+=time;
            cout<<temp<<" "<<curr<<"\n";
        }
        ans=wait/(double)n;
        return ans;
    }
};