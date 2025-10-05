func pacificAtlantic(heights [][]int) [][]int {
    // Handle the edge case of an empty grid.
	if len(heights) == 0 || len(heights[0]) == 0 {
		return [][]int{}
	}

	rows, cols := len(heights), len(heights[0])
	
    // These grids track which cells can be reached from each ocean.
	pacific := make([][]bool, rows)
	atlantic := make([][]bool, rows)
	for i := range pacific {
		pacific[i] = make([]bool, cols)
		atlantic[i] = make([]bool, cols)
	}

	// Start the DFS from all coastal cells.
	for r := 0; r < rows; r++ {
		dfs(r, 0, pacific, heights)          // Left coast (Pacific)
		dfs(r, cols-1, atlantic, heights)    // Right coast (Atlantic)
	}
	for c := 0; c < cols; c++ {
		dfs(0, c, pacific, heights)          // Top coast (Pacific)
		dfs(rows-1, c, atlantic, heights)    // Bottom coast (Atlantic)
	}

	// Find all cells that are true in both grids.
	var result [][]int
	for r := 0; r < rows; r++ {
		for c := 0; c < cols; c++ {
			if pacific[r][c] && atlantic[r][c] {
				result = append(result, []int{r, c})
			}
		}
	}

	return result
}

// dfs explores inland from a given cell as long as the terrain doesn't drop.
func dfs(r, c int, visited [][]bool, heights [][]int) {
	rows, cols := len(heights), len(heights[0])

	// Mark the current cell as visited.
	visited[r][c] = true

	// Define the four directions: up, down, left, right.
	directions := [][]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}

	for _, dir := range directions {
		newR, newC := r+dir[0], c+dir[1]

		// Check if the new cell is valid, not visited, and has a sufficient height.
		if newR >= 0 && newR < rows && newC >= 0 && newC < cols &&
			!visited[newR][newC] && heights[newR][newC] >= heights[r][c] {
			dfs(newR, newC, visited, heights)
		}
	}
}
