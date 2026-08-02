/**
 * @param {number[]} piles
 * @return {boolean}
 */
var stoneGame = function(piles) {
    const n = piles.length;
    const dp = Array.from({ length: n }, () => Array(n).fill(0));

    // Base case: one pile
    for (let i = 0; i < n; i++) {
        dp[i][i] = piles[i];
    }

    // Fill DP table
    for (let len = 2; len <= n; len++) {
        for (let i = 0; i + len - 1 < n; i++) {
            const j = i + len - 1;
            dp[i][j] = Math.max(
                piles[i] - dp[i + 1][j],
                piles[j] - dp[i][j - 1]
            );
        }
    }

    return dp[0][n - 1] > 0;
};