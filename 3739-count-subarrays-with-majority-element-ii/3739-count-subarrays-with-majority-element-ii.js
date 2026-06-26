/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var countMajoritySubarrays = function(nums, target) {
    const n = nums.length;

    let prefix = [0];
    let sum = 0;

    for (let x of nums) {
        sum += (x === target ? 1 : -1);
        prefix.push(sum);
    }

    const vals = [...new Set(prefix)].sort((a, b) => a - b);
    const index = new Map();
    vals.forEach((v, i) => index.set(v, i + 1));

    const bit = new Array(vals.length + 2).fill(0);

    function update(i) {
        while (i < bit.length) {
            bit[i]++;
            i += i & -i;
        }
    }

    function query(i) {
        let res = 0;
        while (i > 0) {
            res += bit[i];
            i -= i & -i;
        }
        return res;
    }

    let ans = 0;

    for (let p of prefix) {
        const idx = index.get(p);
        ans += query(idx - 1);
        update(idx);
    }

    return ans;
};