class Solution {
public:
    static const int MOD = 1e9 + 7;

    int numberOfStableArrays(int zero, int one, int limit) {

        vector<vector<long long>> end0(zero + 1,
                                       vector<long long>(one + 1, 0));
        vector<vector<long long>> end1(zero + 1,
                                       vector<long long>(one + 1, 0));

        // Only zeros
        for (int i = 1; i <= min(zero, limit); i++)
            end0[i][0] = 1;

        // Only ones
        for (int j = 1; j <= min(one, limit); j++)
            end1[0][j] = 1;

        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {

                // End with 0
                if (i > 0) {
                    long long ways = 0;
                    for (int k = 1; k <= limit && i - k >= 0; k++) {
                        ways += end1[i - k][j];
                        ways %= MOD;
                    }
                    end0[i][j] = (end0[i][j] + ways) % MOD;
                }

                // End with 1
                if (j > 0) {
                    long long ways = 0;
                    for (int k = 1; k <= limit && j - k >= 0; k++) {
                        ways += end0[i][j - k];
                        ways %= MOD;
                    }
                    end1[i][j] = (end1[i][j] + ways) % MOD;
                }
            }
        }

        return (end0[zero][one] + end1[zero][one]) % MOD;
    }
};