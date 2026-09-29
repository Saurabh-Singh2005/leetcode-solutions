class Solution {
private:
    int m, n;
    int memo[100][100][201];

    bool solve(int r, int c, int balance, const vector<vector<char>>& grid) {
        if (grid[r][c] == '(') {
            balance++;
        } else {
            balance--;
        }

        if (balance < 0) return false;

        if (r == m - 1 && c == n - 1) {
            return balance == 0;
        }

        if (memo[r][c][balance] != -1) {
            return memo[r][c][balance];
        }

        bool right = false, down = false;
        if (c + 1 < n) right = solve(r, c + 1, balance, grid);
        if (r + 1 < m) down = solve(r + 1, c, balance, grid);

        return memo[r][c][balance] = (right || down);
    }

public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        if ((m + n - 1) % 2 != 0) return false;
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(') return false;

        memset(memo, -1, sizeof(memo));
        return solve(0, 0, 0, grid);
    }
};