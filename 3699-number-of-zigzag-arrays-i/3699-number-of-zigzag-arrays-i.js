/**
 * @param {number} n
 * @param {number} l
 * @param {number} r
 * @return {number}
 */
var zigZagArrays = function(n, l, r) {
    const MOD = 1000000007;
    const m = r - l + 1;

    if (n === 1) return m;

    let up = new Array(m).fill(0);
    let down = new Array(m).fill(0);

    // Length = 2
    for (let v = 0; v < m; v++) {
        up[v] = v;
        down[v] = m - v - 1;
    }

    for (let len = 3; len <= n; len++) {
        const newUp = new Array(m).fill(0);
        const newDown = new Array(m).fill(0);

        // Prefix sums of down
        let prefix = 0;
        for (let v = 0; v < m; v++) {
            newUp[v] = prefix;
            prefix = (prefix + down[v]) % MOD;
        }

        // Suffix sums of up
        let suffix = 0;
        for (let v = m - 1; v >= 0; v--) {
            newDown[v] = suffix;
            suffix = (suffix + up[v]) % MOD;
        }

        up = newUp;
        down = newDown;
    }

    let ans = 0;

    if (n === 2) {
        for (let v = 0; v < m; v++) {
            ans = (ans + up[v] + down[v]) % MOD;
        }
    } else {
        for (let v = 0; v < m; v++) {
            ans = (ans + up[v] + down[v]) % MOD;
        }
    }

    return ans;
};