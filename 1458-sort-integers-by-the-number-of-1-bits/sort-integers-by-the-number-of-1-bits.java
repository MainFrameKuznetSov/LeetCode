class Pair
{
    public int first;
    public int second;

    public Pair(int first,int second)
    {
        this.first=first;
        this.second=second;
    }
}

class Solution {
    public int[] sortByBits(int[] arr) {
        Pair[] pair=new Pair[arr.length];
        for(int i=0;i<arr.length;++i)
            pair[i]=new Pair(arr[i],Integer.bitCount(arr[i]));
        Arrays.sort(pair,(a,b)->
        {
            if(a.second!=b.second)
                return a.second-b.second;
            return a.first-b.first;
        });
        int ans[]=new int[pair.length];
        for(int i=0;i<pair.length;++i)
            ans[i]=pair[i].first;
        return ans;
    }
}