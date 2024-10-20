class Solution {
    public List<String> stringSequence(String target) {
        List<String> ans = new ArrayList<>();
        String temp = "";
        for (int ind = 0; ind < target.length(); ++ind) {
            for (char i = 'a'; i <= target.charAt(ind); ++i) {
                temp += i;
                ans.add(temp);
                temp = temp.substring(0, temp.length() - 1);
            }
            temp += target.charAt(ind);
        }
        return ans;
    }
}