class Solution {
public:
    int m, n;

    long long dfs(vector<vector<int>>& grid, int i, int j)
    {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
        {
            return 0;
        }
        long long count2 = grid[i][j];
        grid[i][j] = 0;
        long long left = dfs(grid, i - 1, j);
        long long right = dfs(grid, i + 1, j);
        long long up = dfs(grid, i, j - 1);
        long long down = dfs(grid, i, j + 1);
        return count2 + left + right + up + down;
    }

    int countIslands(vector<vector<int>>& grid, int k)
    {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] != 0)
                {
                    long long islandSum = dfs(grid, i, j);

                    if(islandSum % k == 0)
                    {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};