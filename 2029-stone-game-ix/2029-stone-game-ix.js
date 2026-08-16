/**
 * @param {number[]} stones
 * @return {boolean}
 */
var stoneGameIX = function(stones) {
    let cnt = [0, 0, 0];

    for (let x of stones) {
        cnt[x % 3]++;
    }

    let c0 = cnt[0];
    let c1 = cnt[1];
    let c2 = cnt[2];

    // If the number of 0-mod-3 stones is even,
    // Alice wins if there is at least one 1 and one 2.
    if (c0 % 2 === 0) {
        return c1 > 0 && c2 > 0;
    }

    // If the number of 0-mod-3 stones is odd,
    // Alice wins only if the difference between
    // the number of 1's and 2's is greater than 2.
    return Math.abs(c1 - c2) > 2;
};