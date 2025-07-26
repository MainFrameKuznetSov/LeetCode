using ppii = pair<pair<int, int>, pair<int, int>>;

class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& pairs) {
        int k = pairs.size();
        long long result = 0;
        for(auto& v : pairs) {
            if(v[0] > v[1]) swap(v[0], v[1]);
            --v[0];
            --v[1];
        }
        sort(pairs.begin(), pairs.end());
        unordered_map<long long, int> pmap;
        for(int i = 0; i < k; ++i) pmap[(pairs[i][0] << 18) + pairs[i][1]] = i;
        vector<ppii> min2(n + 1);
        min2[n] = {{n, n}, {n, n}};
        for(int i = n - 1, j = pairs.size() - 1; i >= 0; --i) {
            min2[i] = min2[i + 1];
            while(j >= 0 && pairs[j][0] == i) {
                if(pairs[j][1] <= min2[i].first.second) min2[i] = {{pairs[j][0], pairs[j][1]}, min2[i].first};
                else if(pairs[j][1] <= min2[i].second.second) min2[i] = {min2[i].first, {pairs[j][0], pairs[j][1]}};
                --j;
            }
        }
        long long total = 0;
        vector<long long> each(k, 0);
        for(int i = 0; i < n; ++i) {
            if(min2[i].first.second < min2[i].second.second) each[pmap[(min2[i].first.first << 18) + min2[i].first.second]] += min2[i].second.second - min2[i].first.second;
            total += min2[i].first.second - i;
        }
        long long improved = 0;
        for(long long i : each) improved = max(improved, i); 
        return improved + total;
    }
};