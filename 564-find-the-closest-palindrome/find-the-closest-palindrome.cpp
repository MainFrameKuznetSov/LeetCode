class Solution {
public:
    string nearestPalindromic(string n) {
        if(n.length()==1)
            return to_string(stoi(n)-1);
        if(n=="10000000000000000")
            return "9999999999999999";
        int d=n.length();
        vector<long long>temp;
        temp.push_back(pow(10,d-1)-1);
        temp.push_back(pow(10,d)+1);
        int mid=(d+1)/2;
        long long pre=stoll(n.substr(0,mid));
        vector<long long>v={pre,pre+1,pre-1};
        for(long long i:v)
        {
            string post=to_string(i);
            if(d%2!=0)
                post.pop_back();
            reverse(post.begin(),post.end());
            string c=to_string(i)+post;
            temp.push_back(stoll(c));
        }
        long long mindiff=LLONG_MAX;
        long long ans;
        long long num=stoll(n);
        for(int i=0;i<5;i++)
        {
            if(temp[i]!=num && abs(temp[i]-num)<mindiff)
            {
                mindiff=abs(temp[i]-num);
                ans=temp[i];
            }
            else if(abs(temp[i]-num)==mindiff)
                ans=min(ans,temp[i]);
        }
        return to_string(ans);
    }
};