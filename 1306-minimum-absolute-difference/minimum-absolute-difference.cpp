class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        int n=arr.size(),mx=(int)2e9;
        for(int i=0;i+1<n;++i)
        {
            int f=arr[i],s=arr[i+1];
            if(s-f<mx)
            {
                ans.clear();
                mx=s-f;
                ans.push_back({f,s});
            }
            else if(s-f==mx)
                ans.push_back({f,s});
        }
        return ans;
    }
};