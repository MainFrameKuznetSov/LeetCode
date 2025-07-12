class Solution {
public:
    unordered_map<string, vector<int>> memo;

    vector<int> earliestAndLatest(int n, int firstPlayer, int secondPlayer) {
        int left = min(firstPlayer, secondPlayer);
        int right = max(firstPlayer, secondPlayer);

        string key =
            to_string(n) + "," + to_string(left) + "," + to_string(right);
        if (memo.count(key))
            return memo[key];

        if (left + right == n + 1)
            return memo[key] = {1, 1};
        if (n == 3 || n == 4)
            return memo[key] = {2, 2};

        if (left - 1 > n - right) {
            int temp = n + 1 - left;
            left = n + 1 - right;
            right = temp;
        }

        int nextRound = (n + 1) / 2;
        int minRound = n, maxRound = 1;

        if (right * 2 <= n + 1) {
            int preLeft = left - 1;
            int midGap = right - left - 1;

            for (int i = 0; i <= preLeft; ++i) {
                for (int j = 0; j <= midGap; ++j) {
                    auto res = earliestAndLatest(nextRound, i + 1, i + j + 2);
                    minRound = min(minRound, 1 + res[0]);
                    maxRound = max(maxRound, 1 + res[1]);
                }
            }
        } else {
            int mirrored = n + 1 - right;
            int preLeft = left - 1;
            int midGap = mirrored - left - 1;
            int innerGap = right - mirrored - 1;

            for (int i = 0; i <= preLeft; ++i) {
                for (int j = 0; j <= midGap; ++j) {
                    int pos1 = i + 1;
                    int pos2 = i + j + 1 + (innerGap + 1) / 2 + 1;
                    auto res = earliestAndLatest(nextRound, pos1, pos2);
                    minRound = min(minRound, 1 + res[0]);
                    maxRound = max(maxRound, 1 + res[1]);
                }
            }
        }

        return memo[key] = {minRound, maxRound};
    }
};