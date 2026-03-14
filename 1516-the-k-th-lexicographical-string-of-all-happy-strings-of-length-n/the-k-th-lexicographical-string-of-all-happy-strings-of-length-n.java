class Solution {

    void recur(int n,String ans,List<String>list)
    {
        if(ans.length()==n)
        {
            list.add(ans);
            return ;
        }
        for(char ch='a';ch<='c';++ch)
        {
            int len=ans.length();
            if(len!=0 && ans.charAt(len-1)==ch)
                continue;
            ans+=ch;
            // System.out.println(ans);
            recur(n,ans,list);
            ans=ans.substring(0,len);
        }
    }

    public String getHappyString(int n, int k) {
        String ans="";
        List<String>list=new ArrayList<>();
        recur(n,ans,list);
        if(list.size()<k)
            return "";
        Collections.sort(list);
        return list.get(k-1);
    }
}