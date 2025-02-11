class Solution {
public:
    string removeOccurrences(string s, string part) {
        int ind=(int)s.find(part);
        while(ind!=string::npos)
        {
            s.erase(ind,(int)part.size());
            ind=(int)s.find(part);
        }
        return s;
    }
};