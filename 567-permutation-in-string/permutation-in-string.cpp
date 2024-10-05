class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m=s1.size(),n=s2.size();
        sort(s1.begin(),s1.end());
        if(m==n)
        {
            sort(s2.begin(),s2.end());
            if(s1==s2)
                return true;
            else
                return false;
        }
        for(int i=0;i<n;++i)
        {
            string temp="";
            for(int j=i;j<i+m && j<n;++j)
                temp+=s2[j];
            sort(temp.begin(),temp.end());
            //cout<<temp<<"\n";
            if(temp==s1)
                return true;
        }
        return false;
    }
};