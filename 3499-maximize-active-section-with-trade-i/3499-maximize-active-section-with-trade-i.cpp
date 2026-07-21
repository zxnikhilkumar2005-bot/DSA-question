class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        string t = "1" + s + "1";

        vector<pair<char, int>> blocks;

        // Run-length encoding
        for (char c : t) {
            if (blocks.empty() || blocks.back().first != c)
                blocks.push_back({c, 1});
            else
                blocks.back().second++;
        }

        // Count original active sections
        int ones = 0;
        for (char c : s)
            if (c == '1')
                ones++;

        int ans = ones;

        int m = blocks.size();

        // Try every surrounded 1-block
        for (int i = 1; i + 1 < m; i++) {
            if (blocks[i].first == '1' &&
                blocks[i - 1].first == '0' &&
                blocks[i + 1].first == '0') {

                ans = max(ans, ones + blocks[i - 1].second + blocks[i + 1].second);
            }
        }

        return ans;
    }
};