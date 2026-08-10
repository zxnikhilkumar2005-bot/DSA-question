var getHappyString = function(n, k) {
    let result = "";
    let count = 0;

    function backtrack(str) {
        // If we already found kth string
        if (result !== "") return;

        // String complete
        if (str.length === n) {
            count++;

            if (count === k) {
                result = str;
            }

            return;
        }

        // Try a, b, c in lexicographical order
        for (let ch of ['a', 'b', 'c']) {

            // Adjacent characters must be different
            if (str.length > 0 && str[str.length - 1] === ch) {
                continue;
            }

            backtrack(str + ch);
        }
    }

    backtrack("");

    return result;
};