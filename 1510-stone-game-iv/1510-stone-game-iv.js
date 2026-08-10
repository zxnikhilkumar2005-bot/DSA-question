var winnerSquareGame = function(n) {
    const dp = new Array(n + 1).fill(false);

    // dp[0] = false
    // 0 stones -> no move -> lose

    for (let i = 1; i <= n; i++) {
        for (let j = 1; j * j <= i; j++) {
            const square = j * j;

            // If opponent loses after our move,
            // then we can win.
            if (dp[i - square] === false) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];
};