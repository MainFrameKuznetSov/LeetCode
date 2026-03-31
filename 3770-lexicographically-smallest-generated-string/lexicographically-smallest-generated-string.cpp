class Solution {
public:
    string generateString(string str1, string str2) {
        int n=str1.size(),m=str2.size();
        string pre(n+m-1,'a');
        vector<int>aux(n+m-1,0);
        for(int i=0;i<n;++i) 
        {
            if(str1[i]=='T') 
            {
                for(int j=i;j<i+m;++j) 
                {
                    if(aux[j] && pre[j]!=str2[j-i])
                        return "";
                    else 
                    {
                        pre[j]=str2[j-i];
                        aux[j]=1;
                    }
                }
            }
        }

        for(int i=0;i<n;++i)
        {
            if(str1[i]=='F') 
            {
                bool f=false;
                int idx=-1;
                for(int j=i+m-1;j>=i;--j) 
                {
                    if(str2[j-i]!=pre[j])
                        f=true;
                    if(idx==-1 && !aux[j])
                        idx=j;
                }
                if(f)
                    continue;
                else if(idx!=-1) 
                    pre[idx]='b';
                else
                    return "";
            }
        }
        return pre;
    }
};