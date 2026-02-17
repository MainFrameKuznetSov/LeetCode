class Pair
{
    public int first;
    public int second;

    Pair(int first,int second)
    {
        this.first=first;
        this.second=second;
    }

}

class MinStack {

    private Stack<Pair> stk;

    public MinStack() {
        stk=new Stack<>();
    }
    
    public void push(int val) {
        if(stk.isEmpty())
            stk.push(new Pair(val,val));
        else 
        {
            int min=Math.min(val,stk.peek().second);
            stk.push(new Pair(val,min));
        }
    }
    
    public void pop() {
        if(!stk.isEmpty())
            stk.pop();
    }
    
    public int top() {
        return stk.peek().first;
    }
    
    public int getMin() {
        return stk.peek().second;
    }
}
