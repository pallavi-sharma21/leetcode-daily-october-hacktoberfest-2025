class Solution:
    def swimInWater(self, grid: list[list[int]]) -> int:
        n = len(grid)
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]

        def dfs(r, c, mid, seen):
            if r == n - 1 and c == n - 1:
                return True
            seen[r][c] = True
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < n and not seen[nr][nc] and grid[nr][nc] <= mid:
                    if dfs(nr, nc, mid, seen):
                        return True
            return False

        def possible(mid):
            if grid[0][0] > mid:
                return False
            seen = [[False] * n for _ in range(n)]
            return dfs(0, 0, mid, seen)

        lo, hi = grid[0][0], max(max(row) for row in grid)
        while lo < hi:
            mid = (lo + hi) // 2
            if possible(mid):
                hi = mid
            else:
                lo = mid + 1
        return lo
