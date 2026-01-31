class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n=temperatures.length;
        int results[]=new int[n];
        Stack<Integer>stk=new Stack<>();
        for(int i=0;i<n;++i)
        {
            while(!stk.isEmpty() && temperatures[i]>temperatures[stk.peek()])
                results[stk.peek()]=i-stk.pop();
            stk.push(i);
        }
        return results;
    }
}