/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    const result = [];

    function backtrack(curr, open, close) {
        if (curr.length === 2 * n) {
            result.push(curr);
            return;
        }

        if (open < n) {
            backtrack(curr + "(", open + 1, close);
        }

        if (close < open) {
            backtrack(curr + ")", open, close + 1);
        }
    }

    backtrack("", 0, 0);
    return result;
};