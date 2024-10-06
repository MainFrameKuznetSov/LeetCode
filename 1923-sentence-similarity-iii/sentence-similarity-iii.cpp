class Solution {
private:
    vector<string> convert(string s)
    {
        s+=" ";
        vector<string>ans;
        string word="";
        for(int i=0;i<s.size();++i)
        {
            if(s[i]==' ')
            {
                ans.push_back(word);
                word="";
            }
            else
                word+=s[i];
        }
        return ans;
    }
public:
    bool areSentencesSimilar(string s1, string s2) {
        if(s1.size()<s2.size()) 
            swap(s1,s2);
        vector<string>vx,vy;
        vx=convert(s1);
        vy=convert(s2);
        int l=0;
        for(int i=0;i<vy.size();++i) 
        {
            if(vx[i]==vy[i])
                ++l;
            else
                break;
        }
        int ind=vx.size()-1,r=vy.size();
        for(int i=vy.size()-1;i>=0;--i)
        {
            if(vy[i]==vx[ind])
            {
                --ind;
                r=i;
            }
            else
                break;
        }
        return r<=l;
    }
};