class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<vector<bool>> dp(4, vector<bool>(MAXX, false));
        dp[0][0] = true;

        for (int v : nums) {
            auto ndp = dp;

            for (int cnt = 0; cnt <= 2; cnt++) {
                for (int x = 0; x < MAXX; x++) {
                    if (!dp[cnt][x]) continue;

                    // Use current index once
                    ndp[cnt + 1][x ^ v] = true;

                    // Use current index twice
                    if (cnt + 2 <= 3)
                        ndp[cnt + 2][x] = true;

                    // Use current index three times
                    if (cnt + 3 <= 3)
                        ndp[cnt + 3][x ^ v] = true;
                }
            }

            dp = move(ndp);
        }

        int ans = 0;
        for (int x = 0; x < MAXX; x++)
            if (dp[3][x]) ans++;

        return ans;
    }
};