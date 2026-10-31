class Solution {
public:
    int left = 0;
    int up = 1;
    int mod = 1e9 + 7;
    int m, n;

    int solve(vector<vector<int>>& grid, int i, int j, int camefrom, vector<vector<array<int, 2>>>& t) {
       
        if (i >= m || j >= n) {
            return 0;
        }

       
        if (i == m - 1 && j == n - 1) {
            return 1;
        }

        
        if (t[i][j][camefrom] != -1) {
            return t[i][j][camefrom];
        }

        
        if (grid[i][j] == 1) {
            if (camefrom == left) {
                return t[i][j][camefrom] = solve(grid, i + 1, j, up, t);
            } else {
                return t[i][j][camefrom] = solve(grid, i, j + 1, left, t);
            }
        }

       
        int totalpathcount = 0;
        totalpathcount = (totalpathcount + solve(grid, i, j + 1, left, t)) % mod;
        totalpathcount = (totalpathcount + solve(grid, i + 1, j, up, t)) % mod;
        
        
        return t[i][j][camefrom] = totalpathcount;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
       
        vector<vector<array<int, 2>>> t(m, vector<array<int, 2>>(n, {-1, -1}));

        return solve(grid, 0, 0, left, t);
    }
};