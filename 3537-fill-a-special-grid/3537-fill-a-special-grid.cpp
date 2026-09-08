class Solution {
public:

    void f(int i, int j, int len,
           int start, int end,
           vector<vector<int>>& grid) {

        if (start == end) {
            grid[i][j] = start;
            return;
        }

        int total = end - start + 1;
        int k = len / 2;
        int grp = total / 4;

        // Top-right
        f(i, j + k, k,
          start, start + grp - 1, grid);

        // Bottom-right
        f(i + k, j + k, k,
          start + grp, start + 2 * grp - 1, grid);

        // Bottom-left
        f(i + k, j, k,
          start + 2 * grp, start + 3 * grp - 1, grid);

        // Top-left
        f(i, j, k,
          start + 3 * grp, end, grid);
    }

    vector<vector<int>> specialGrid(int n) {

        int size = 1 << n;

        vector<vector<int>> grid(size, vector<int>(size));

        f(0, 0, size, 0, size * size - 1, grid);

        return grid;
    }
};