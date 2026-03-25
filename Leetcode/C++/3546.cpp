class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long pref[n + 3][m + 3];
        memset(pref, 0, sizeof pref);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + grid[i][j];
        long long sum = pref[n][m];
        if (sum & 1) return 0;
        for (int i = 1; i <= n; ++i)
            if (pref[i][m] == sum / 2) return 1;
        for (int i = 1; i <= m; ++i)
            if (pref[n][i] == sum / 2) return 1;
        return 0;
    }
};