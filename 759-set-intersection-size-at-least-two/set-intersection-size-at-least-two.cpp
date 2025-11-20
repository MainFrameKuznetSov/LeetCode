class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[&](auto a,auto b)
            {
                if(a[1]==b[1])
                    return a[0]>b[0];
                return a[1]<b[1];
            }
        );
        int ans=0,f=-1,s=-1;
        for(auto it:intervals)
        {
            int lo=it[0],hi=it[1];
            if(lo>s)
            {
                f=hi-1;
                s=hi;
                ans+=2;
            }
            else if(lo>f)
            {
                f=s;
                s=hi;
                ++ans;
            }
        }
        return ans;
    }
};