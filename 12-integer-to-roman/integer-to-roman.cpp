class Solution {
public:

    int val[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    string rom[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

    string intToRoman(int num) {
        string ans="";
        int ind=0;
        while(num)
        {
            while(num>=val[ind])
            {
                ans+=rom[ind];
                num-=val[ind];
            }
            ++ind;
        }
        return ans;
    }
};