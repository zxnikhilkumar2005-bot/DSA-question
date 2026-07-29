class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();

        // trailingZeros[i] = number of trailing zeros in row i
        vector<int> trailingZeros(n);

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0)
                    cnt++;
                else
                    break;
            }
            trailingZeros[i] = cnt;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int need = n - 1 - i;

            int j = i;
            while (j < n && trailingZeros[j] < need)
                j++;

            if (j == n)
                return -1;

            while (j > i) {
                swap(trailingZeros[j], trailingZeros[j - 1]);
                ans++;
                j--;
            }
        }

        return ans;
    }
};