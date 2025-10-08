var swimInWater = function(grid) {
    const n = grid.length;
    const directions = [[0,1], [1,0], [0,-1], [-1,0]];

    const dfs = (r, c, mid, seen) => {
        if (r === n - 1 && c === n - 1) return true;
        seen[r][c] = true;

        for (const [dr, dc] of directions) {
            const nr = r + dr, nc = c + dc;
            if (
                nr >= 0 && nr < n &&
                nc >= 0 && nc < n &&
                !seen[nr][nc] &&
                grid[nr][nc] <= mid
            ) {
                if (dfs(nr, nc, mid, seen)) return true;
            }
        }
        return false;
    };

    const possible = (mid) => {
        if (grid[0][0] > mid) return false;
        const seen = Array.from({ length: n }, () => Array(n).fill(false));
        return dfs(0, 0, mid, seen);
    };

    let lo = grid[0][0];
    let hi = Math.max(...grid.flat());

    while (lo < hi) {
        const mid = Math.floor((lo + hi) / 2);
        if (possible(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    return lo;
};
