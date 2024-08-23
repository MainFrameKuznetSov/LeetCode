class Solution {
public:
    int hcf(int a,int b) 
    {
        return b==0?a:hcf(b,a%b);
    }
    string fractionAddition(string expr) {
        if(expr[0]!='-') 
            expr="+"+expr;
        int num=0,den=1,i=0;
        while(i<expr.size()) 
        {
            int sign=expr[i++]=='+'?1:-1;
            int num1=0,den1=0;
            while(isdigit(expr[i])) 
                num1=num1*10+(expr[i++]-'0');
            i++;
            while(i<expr.size() && isdigit(expr[i])) 
                den1=den1*10+(expr[i++]-'0');
            num=num*den1+sign*num1*den;
            den=den*den1;
            int h=abs(hcf(num,den));
            num/=h;
            den/=h;
        }
        return to_string(num)+"/"+to_string(den);
    }
};