class Solution {
public:
    bool areSimilar(vector<vector<int>>& a, int k) {
        int n = a.size(), m = a[0].size();
        int odd_idx = (m + k) % m;
        int even_idx = (m - (m + k) % m + m) % m;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (i & 1 && a[i][j] != a[i][(j + odd_idx) % m])
                    return false;
                else if (i & 1 ^ 1 && a[i][j] != a[i][(j + even_idx) % m])
                    return false;
        return true;
    }
};