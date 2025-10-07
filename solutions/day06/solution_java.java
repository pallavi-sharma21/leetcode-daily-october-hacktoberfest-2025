package solutions.day06;
class Solution {
    public int swimInWater(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        // Directions to move: right, down, left, up
        int[][] directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        // Binary search range:
        // lo starts at the height of the starting cell
        // hi is the maximum height found in the grid
        int lo = grid[0][0], hi = 0;
        for (int[] row : grid)
            for (int val : row)
                hi = Math.max(hi, val);
        
        // Binary search on the time (water level)
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            // If we can reach the end when water level = mid,
            // try to find a smaller possible value
            if (possible(grid, mid, m, n, directions)) hi = mid;
            else lo = mid + 1;  // Otherwise, increase the level
        }
        // 'lo' will be the minimum time required
        return lo;
    }
    
    // Check if destination is reachable when water level = mid
    private boolean possible(int[][] grid, int mid, int m, int n, int[][] directions) {
        // If starting point itself is higher than current level, impossible
        if (grid[0][0] > mid) return false;
        boolean[][] seen = new boolean[m][n];  // visited cells
        // Perform DFS traversal starting from (0, 0)
        return dfs(grid, 0, 0, mid, seen, m, n, directions);
    }
    
    // DFS to explore reachable cells under current water level
    private boolean dfs(int[][] grid, int r, int c, int mid, boolean[][] seen, int m, int n, int[][] directions) {
        // If we reached the target cell (bottom-right), return true
        if (r == m - 1 && c == n - 1) return true;
        seen[r][c] = true;
        
        // Explore all 4 directions
        for (int[] dir : directions) {
            int nr = r + dir[0], nc = c + dir[1];
            // Stay within grid and avoid revisiting
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !seen[nr][nc]) {
                // Move only if the next cell’s height <= current water level
                if (grid[nr][nc] <= mid) {
                    // Recursively check if path from this cell can reach destination
                    if (dfs(grid, nr, nc, mid, seen, m, n, directions))
                        return true;
                }
            }
        }
        // No valid path found from this route
        return false;
    }
}
