class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> cnt;

        for (int x : nums)
            cnt[x]++;

        int ans = 1;

        // Handle value 1 separately
        if (cnt.count(1)) {
            ans = max(ans, (cnt[1] % 2) ? cnt[1] : cnt[1] - 1);
        }

        for (auto &[x, f] : cnt) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (true) {
                if (!cnt.count(cur)) {
                    len--;
                    break;
                }

                if (cnt[cur] == 1) {
                    len++;
                    break;
                }

                // Need two copies of current value
                len += 2;

                // Prevent overflow
                if (cur > 1000000000LL / cur) {
                    len--;
                    break;
                }

                long long nxt = cur * cur;

                // If next level doesn't exist, current level can't contribute two copies
                if (!cnt.count(nxt)) {
                    len--;
                    break;
                }

                cur = nxt;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};