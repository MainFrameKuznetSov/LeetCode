class Solution {
    public boolean hasAllCodes(String s, int k) {
        Map<String,Integer>map=new HashMap<>();
        int n=s.length();
        for(int i=0;i+k<=n;++i)
        {
            String substr=s.substring(i,i+k);
            map.put(substr,1);
        }
        if(map.size()>=Math.pow(2,k))
            return true;
        return false;
    }
}