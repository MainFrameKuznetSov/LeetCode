class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n=arr.size();
        vector<string>temp;
        bool flag=true;
        for(int i=0;i<n;++i)
        {
            temp.push_back(arr[i]);
            for(int j=0;j<n;++j)
            {
                if(arr[i]==arr[j] && i!=j)
                {
                    temp.pop_back();
                    break;
                }
            }
        }
        for(int i=0;i<temp.size();++i)
            cout<<temp[i]<<" ";
        if(temp.size()<k)
            return "";
        else
            return temp[k-1];
    }
};