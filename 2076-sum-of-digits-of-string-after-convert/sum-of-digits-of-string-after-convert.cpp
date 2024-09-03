class Solution {
public:
    int getLucky(string s, int k) {
        string temp="";
        for(char ch:s)
            temp+=to_string(ch-'a'+1);
        while(k)
        {
            int val=0;
            for(char ch:temp)
                val+=ch-'0';
            temp=to_string(val);
            --k;
        }
        return stoi(temp);
    }
};