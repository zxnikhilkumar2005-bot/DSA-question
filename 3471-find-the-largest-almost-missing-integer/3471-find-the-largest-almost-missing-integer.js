var largestInteger = function(nums, k) {
    let count = new Map();

    // Traverse all subarrays of size k
    for (let i = 0; i <= nums.length - k; i++) {
        let seen = new Set();

        // Store unique elements of current window
        for (let j = i; j < i + k; j++) {
            seen.add(nums[j]);
        }

        // Count how many subarrays contain each number
        for (let x of seen) {
            count.set(x, (count.get(x) || 0) + 1);
        }
    }

    let ans = -1;

    // Find the largest number appearing in exactly one subarray
    for (let [x, freq] of count) {
        if (freq === 1) {
            ans = Math.max(ans, x);
        }
    }

    return ans;
};