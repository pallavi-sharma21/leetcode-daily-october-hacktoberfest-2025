void bfs(queue<int>& q, vector<vector<int>>& heights, uint8_t mark) {
    while (!q.empty()) {
        int ij=q.front();
        q.pop();
        auto [i, j]=div(ij, n);
        for (int a=0; a<4; a++) {
            int r=i+dir[a], s=j+dir[a+1];
            if (isOutside(r, s)) continue;
            int rs=idx(r, s);
            if ((status[rs]&mark)||heights[r][s]<heights[i][j])
                continue; 
            status[rs]|=mark;
            q.push(rs);
        }
    }
}
