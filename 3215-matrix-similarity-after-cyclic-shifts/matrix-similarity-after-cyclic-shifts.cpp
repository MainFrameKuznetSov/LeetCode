class Solution {
public:

    void reverse(vector<int>&v,int l,int r)
    {
        while(l<r)
        {
            swap(v[l],v[r]);
            ++l;
            --r;
        }
    }

    vector<int> getRotatedArray(vector<int>row,int k)
    {
        int n=row.size();
        k=k%n;
        reverse(row,0,n-1);
        reverse(row,0,k-1);
        reverse(row,k,n-1);
        return row;
    }

    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        // k=k%n;
        for(int i=0;i<n;++i)
        {
            vector<int>row=mat[i];
            if(row!=getRotatedArray(row,k))
                return false;
        }
        return true;
    }
};