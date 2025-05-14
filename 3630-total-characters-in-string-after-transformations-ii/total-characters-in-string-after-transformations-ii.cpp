class Solution {
private:
    int MOD = 1e9 + 7;
public:
    int lengthAfterTransformations(std::string s, int t, std::vector<int>& nums) {
        std::vector<std::vector<long long>> transformationMatrix(26, std::vector<long long>(26, 0));
        

        for (int i = 0; i < 26; i++) {
            for (int j = 1; j <= 25; j++) {
                if (nums[(26 + i - j) % 26] >= ((26 + j) % 26)) {
                    transformationMatrix[(26 + i - j) % 26][i] = 1;
                }
            }
        }

        
        std::vector<long long> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        
        while (t > 0) {
            if (t & 1) {
                std::vector<long long> newFreq(26, 0);
                for (int i = 0; i < 26; i++) {
                    long long newV = 0;
                    for (int j = 0; j < 26; j++) {
                        newV += freq[j] * transformationMatrix[j][i];
                        newV %= MOD;
                    }
                    newFreq[i] = newV;
                }
                freq = newFreq;
            }
            t >>= 1;
            
            
            std::vector<std::vector<long long>> newTransformationMatrix(26, std::vector<long long>(26, 0));
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    long long newV = 0;
                    for (int k = 0; k < 26; k++) {
                        newV += transformationMatrix[i][k] * transformationMatrix[k][j];
                        newV %= MOD;
                    }
                    newTransformationMatrix[i][j] = newV;
                }
            }
            transformationMatrix = newTransformationMatrix;
        }

        
        long long ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += freq[i];
            ans %= MOD;
        }
        
        return (int)ans;
    }
};