var pacificAtlantic = function(heights) {
    const m = heights.length, n = heights[0].length;

    // visited matrices for pacific and atlantic
    const pac = Array.from({ length: m }, () => Array(n).fill(false));
    const atl = Array.from({ length: m }, () => Array(n).fill(false));

    // directions (up, down, left, right)
    const dirs = [[1,0],[-1,0],[0,1],[0,-1]];

    const dfs = (i, j, visited, prevHeight) => {
        // out of bounds or already visited or cannot flow uphill
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] || heights[i][j] < prevHeight) {
            return;
        }
        visited[i][j] = true;
        for (let [dx, dy] of dirs) {
            dfs(i + dx, j + dy, visited, heights[i][j]);
        }
    };

    // start DFS from Pacific borders
    for (let i = 0; i < m; i++) {
        dfs(i, 0, pac, heights[i][0]);          // left edge
        dfs(i, n - 1, atl, heights[i][n - 1]);  // right edge
    }
    for (let j = 0; j < n; j++) {
        dfs(0, j, pac, heights[0][j]);          // top edge
        dfs(m - 1, j, atl, heights[m - 1][j]);  // bottom edge
    }

    // collect results where both pacific & atlantic are reachable
    const res = [];
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (pac[i][j] && atl[i][j]) {
                res.push([i, j]);
            }
        }
    }
    return res;
};
