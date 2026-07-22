class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();

        if (k > n) return false;

        int total = 1 << k;
        vector<bool> seen(total, false);

        int mask = total - 1;
        int num = 0;
        int count = 0;

        for (int i = 0; i < n; i++) {
            num = ((num << 1) & mask) | (s[i] - '0');

            if (i >= k - 1 && !seen[num]) {
                seen[num] = true;
                count++;
                if (count == total)
                    return true;
            }
        }

        return false;
    }
};