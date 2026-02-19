class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        set<int>st;
        for(int i:bulbs)
        {
            if(st.count(i))
                st.erase(i);
            else
                st.insert(i);
        }
        return vector<int>(st.begin(),st.end());
    }
};