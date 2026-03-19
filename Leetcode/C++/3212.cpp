class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& a) {
        vector<vector<int>> grid(a.size(), vector<int>(a[0].size()));
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                grid[i][j] = (a[i][j] == 'X' ? -1 : (a[i][j] == 'Y' ? 1 : 0));
        vector<vector<int>> check(n + 3, vector<int>(m + 3)), pref(n + 3, vector<int>(m + 3));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                check[i + 1][j + 1] = check[i + 1][j] | check[i][j + 1] | (grid[i][j] == -1);
                pref[i + 1][j + 1] = pref[i + 1][j] + pref[i][j + 1] - pref[i][j] + grid[i][j];
            }
        int ans = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (!pref[i][j] && check[i][j])
                    ++ans;
        return ans;
    }
};