class Solution {
    const int MOD = 1e9 + 7;
    int getScore(int x) {
        int res = (x % 2 == 0);
        while (x % 2 == 0) {
            x /= 2;
        }

        for (int i = 3; i <= sqrt(x); i += 2) {
            if (x % i == 0)
                res++;
            while (x % i == 0) {
                x /= i;
            }
        }
        if (x > 1) res++;
        return res;
    }

    vector<int> getMaxOnLeft(vector<int> &a) {
        int n = a.size();
        vector<int> ans(n);
        
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && a[s.top()] < a[i])
                s.pop();
            ans[i] = (s.empty() ? -1 : s.top());
            s.push(i);
        }
        return ans;
    }

    vector<int> getMaxOnRight(vector<int> &a) {
        int n = a.size();
        vector<int> ans(n);

        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && a[s.top()] <= a[i])
                s.pop();
            ans[i] = (s.empty() ? n : s.top());
            s.push(i);
        }
        return ans;
    }

    long long power(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b % 2 != 0)
                (res *= a) %= MOD;
            (a *= a) %= MOD;
            b /= 2;
        }
        return res;
    }

public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> scores(n);
        for (int i = 0; i < n; i++)
            scores[i] = getScore(nums[i]);
        vector<int> leftMax = getMaxOnLeft(scores);
        vector<int> rightMax = getMaxOnRight(scores);
        priority_queue<pair<int, long long>> pq;
        for (int i = 0; i < n; i++) {
            long long cnt = 1LL * (i - leftMax[i]) * (rightMax[i] - i);
            pq.push({nums[i], cnt});
        }

        
        long long res = 1;
        while (!pq.empty() && k > 0) {
            int x = pq.top().first;
            long long cnt = pq.top().second;
            pq.pop();

            long long b = min(1LL * k, cnt);
            k -= b;
            res *= power(1LL * x, b);
            res %= MOD;
        }

        return res;
    }
};