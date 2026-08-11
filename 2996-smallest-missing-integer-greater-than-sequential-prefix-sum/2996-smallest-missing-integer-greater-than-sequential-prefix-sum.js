var missingInteger = function(nums) {
    let sum = nums[0];

    // Find the sum of the longest sequential prefix
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] === nums[i - 1] + 1) {
            sum += nums[i];
        } else {
            break;
        }
    }

    // Store all numbers in a Set
    const set = new Set(nums);

    // Find the smallest missing integer >= sum
    while (set.has(sum)) {
        sum++;
    }

    return sum;
};