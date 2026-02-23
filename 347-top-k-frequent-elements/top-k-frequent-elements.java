class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        Map<Integer,Integer>freqMap=new HashMap<>();
        for(int i:nums)
            freqMap.put(i,freqMap.getOrDefault(i,0)+1);
        PriorityQueue<Integer>pq=new PriorityQueue<>(
            (a,b)->{
                return freqMap.get(b)-freqMap.get(a);
        });
        int limit=freqMap.size()-k,ind=0;
        int ans[]=new int[k];
        for(int i:freqMap.keySet())
        {
            pq.add(i);
            if(pq.size()>limit)
                ans[ind++]=pq.poll();
        }
        // while(ind<k && !pq.isEmpty())
        //     ans[ind++]=pq.poll();
        return ans;
    }
}