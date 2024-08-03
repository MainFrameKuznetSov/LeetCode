class Solution {
public:
    bool canBeEqual(vector<int>& targetArray, vector<int>& currentArray) {
        vector<int>freq(1001,0);
        int ans=0;
        for (int i=0;i<targetArray.size();++i) 
        {
            if(freq[targetArray[i]]++==0) 
                ++ans;
            if(freq[currentArray[i]]--==1) 
                --ans;
        }
        
        return ans== 0;
    }
};