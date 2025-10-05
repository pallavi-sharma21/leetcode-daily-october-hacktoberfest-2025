impl Solution {
    pub fn pacific_atlantic(heights: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        // Handle the edge case of an empty grid.
        if heights.is_empty() || heights[0].is_empty() {
            return vec![];
        }

        let m = heights.len();
        let n = heights[0].len();

        // `pacific_reachable` will store cells from which water can flow to the Pacific.
        let mut pacific_reachable = vec![vec![false; n]; m];
        // `atlantic_reachable` will store cells from which water can flow to the Atlantic.
        let mut atlantic_reachable = vec![vec![false; n]; m];

        // Start DFS from all border cells for both oceans.
        for r in 0..m {
            // Left border (Pacific)
            Self::dfs(r, 0, &heights, &mut pacific_reachable);
            // Right border (Atlantic)
            Self::dfs(r, n - 1, &heights, &mut atlantic_reachable);
        }

        for c in 0..n {
            // Top border (Pacific)
            Self::dfs(0, c, &heights, &mut pacific_reachable);
            // Bottom border (Atlantic)
            Self::dfs(m - 1, c, &heights, &mut atlantic_reachable);
        }

        // Find the intersection of cells reachable from both oceans.
        let mut result = Vec::new();
        for r in 0..m {
            for c in 0..n {
                if pacific_reachable[r][c] && atlantic_reachable[r][c] {
                    result.push(vec![r as i32, c as i32]);
                }
            }
        }

        result
    }

    /// Helper DFS function to find all reachable cells from a starting point.
    /// Traverses "uphill" from the ocean borders inland.
    fn dfs(r: usize, c: usize, heights: &Vec<Vec<i32>>, visited: &mut Vec<Vec<bool>>) {
        // If we've already visited this cell, we don't need to explore it again.
        if visited[r][c] {
            return;
        }
        
        // Mark the current cell as reachable.
        visited[r][c] = true;
        
        let m = heights.len();
        let n = heights[0].len();
        let current_height = heights[r][c];

        // Define the four cardinal directions (North, South, East, West).
        let directions: [(i32, i32); 4] = [(0, 1), (0, -1), (1, 0), (-1, 0)];
        
        for (dr, dc) in directions {
            let new_r = r as i32 + dr;
            let new_c = c as i32 + dc;

            // Check if the neighbor is within the grid bounds.
            if new_r >= 0 && new_r < m as i32 && new_c >= 0 && new_c < n as i32 {
                let nr = new_r as usize;
                let nc = new_c as usize;
                
                // If the neighbor hasn't been visited and its height allows "uphill" flow,
                // continue the DFS from there.
                if !visited[nr][nc] && heights[nr][nc] >= current_height {
                    Self::dfs(nr, nc, heights, visited);
                }
            }
        }
    }
}
