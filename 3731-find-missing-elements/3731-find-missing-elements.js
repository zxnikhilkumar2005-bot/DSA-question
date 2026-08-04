/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findMissingElements = function(nums) {
    let minVal = Math.min(...nums);
    let maxVal = Math.max(...nums);

    const set = new Set(nums);
    const ans = [];

    for (let i = minVal + 1; i < maxVal; i++) {
        if (!set.has(i)) {
            ans.push(i);
        }
    }

    return ans;
};