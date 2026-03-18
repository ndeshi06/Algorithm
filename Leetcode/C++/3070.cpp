class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> pref(n + 3, vector<int>(m + 3));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + grid[i][j];
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (pref[i][j] <= k) ++ans;
        return ans;
    }
};