class Solution {
    public String reverseWords(String s) {
        s=s.trim()+" ";
        String temp="",ans="",fin="";
        for(int i=0;i<s.length();++i)
        {
            if(s.charAt(i)==' ')
            {
                ans=temp+" "+ans;
                temp="";
            }
            else
                temp+=s.charAt(i);
        }
        ans=ans.trim();
        fin+=ans.charAt(0)+"";
        for(int i=1;i<ans.length();++i)
        {
            if(!(ans.charAt(i)==' ' && ans.charAt(i-1)==' '))
                fin+=ans.charAt(i);
        }
        return fin;
    }
}