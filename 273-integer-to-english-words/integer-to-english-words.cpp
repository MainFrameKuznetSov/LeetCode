class Solution {
public:
    string solve(int num)
    {
        string unit[]={"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
        string tens[]={"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        string endZero[]={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
        string ans="";
        if(num>99)
            ans+=unit[num/100]+" Hundred ";
        num%=100;
        if(num<20 && num>9)
            ans+=tens[num-10]+" ";
        else
        {
            if(num>=20)
                ans+=endZero[num/10]+" ";
            num%=10;
            if(num>0)
                ans+=unit[num]+" ";
        }
        return ans;
    }
    string numberToWords(int num) {
        if(num==0)
            return "Zero";
        string left[]={"Thousand","Million","Billion"};
        string ans=solve(num%1000);
        num/=1000;
        for(int i=0;i<3;++i)
        {
            if(num%1000>0 && num>0)
                ans=solve(num%1000)+left[i]+" "+ans;
            num/=1000;
        }
        return ans.empty()?ans:ans.substr(0,ans.size()-1);
    }
};