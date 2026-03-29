class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for(int i=0;i<=3;++i)
        {
            // cout<<i<<"-->"<<s1<<"  "<<s2<<"\n";
            if(s1[i]!=s2[i])
            {
                if(i+2<=3)
                {
                    if(s1[i]!=s2[i+2])
                        return false;
                    else
                        swap(s2[i],s2[i+2]);
                    continue;
                }
                if(i-2>=0)
                {
                    if(s1[i]!=s2[i-2])
                        return false;
                    else
                        swap(s2[i],s2[i-2]);
                    continue;
                }
                return false;
            }
        }
        return true;
    }
};