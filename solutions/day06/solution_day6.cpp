// Add libraries if you want to run it in VS Code

class Solution {
public:
    struct DSU {
        vector<int> parent, rank;
        DSU(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            iota(parent.begin(), parent.end(), 0);
        }
        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }
        void unite(int x, int y) {
            int rx = find(x), ry = find(y);
            if (rx == ry) return;
            if (rank[rx] < rank[ry]) swap(rx, ry);
            parent[ry] = rx;
            if (rank[rx] == rank[ry]) rank[rx]++;
        }
    };

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<array<int, 3>> cells;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cells.push_back({grid[i][j], i, j});
            }
        }

        sort(cells.begin(), cells.end());

        DSU dsu(n * n);
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<bool>> open(n, vector<bool>(n, false));

        auto idx = [&](int i, int j){ return i * n + j; };

        for (auto &cell : cells) {
            int h = cell[0], i = cell[1], j = cell[2];
            open[i][j] = true;

            for (auto &d : dirs) {
                int ni = i + d[0], nj = j + d[1];
                if (ni >= 0 && nj >= 0 && ni < n && nj < n && open[ni][nj])
                    dsu.unite(idx(i,j), idx(ni,nj));
            }

            if (dsu.find(0) == dsu.find(n * n - 1))
                return h;
        }

        return -1;
    }
};