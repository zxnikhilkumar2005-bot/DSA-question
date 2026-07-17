class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<long long> freq(mx + 1, 0);
        for (int x : nums) freq[x]++;

        // cnt[d] = numbers divisible by d
        vector<long long> cnt(mx + 1, 0);
        for (int d = 1; d <= mx; d++) {
            for (int j = d; j <= mx; j += d)
                cnt[d] += freq[j];
        }

        // exact[d] = pairs whose gcd is exactly d
        vector<long long> exact(mx + 1, 0);

        for (int d = mx; d >= 1; d--) {
            long long c = cnt[d];
            exact[d] = c * (c - 1) / 2;

            for (int j = d + d; j <= mx; j += d)
                exact[d] -= exact[j];
        }

        // prefix counts
        vector<long long> prefix(mx + 1, 0);
        for (int d = 1; d <= mx; d++)
            prefix[d] = prefix[d - 1] + exact[d];

        vector<int> ans;

        for (long long q : queries) {
            // Find smallest gcd value whose prefix > q
            int l = 1, r = mx;
            while (l < r) {
                int mid = (l + r) / 2;
                if (prefix[mid] > q)
                    r = mid;
                else
                    l = mid + 1;
            }
            ans.push_back(l);
        }

        return ans;
    }
};