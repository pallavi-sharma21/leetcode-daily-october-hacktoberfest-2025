class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m= heights.size();
        int n= heights[0].size();
        vector<vector<int>>visP(m, vector<int>(n,0)), visA(m,vector<int>(n,0));
        vector<pair<int,int>>dirs={{0,1}, {0,-1}, {1,0}, {-1,0}};
        queue<pair<int,int>>qA, qP;
        for(int i=0;i<n;i++){
            qP.push({0, i});visP[0][i]=1;
            qA.push({m-1,i});visA[m-1][i]=1;
        }
        for(int i=0;i<m;i++){
            qP.push({i,0});visP[i][0]=1;
            qA.push({i,n-1});visA[i][n-1]=1;
        }

        while(!qP.empty()){
            auto [x,y] = qP.front(); qP.pop();
            for(auto [dx,dy]: dirs){
                int i = x+dx, j=y+dy;
                if(i>=0 && j>=0 && i<m && j<n && !visP[i][j] and heights[x][y]<=heights[i][j]){
                    qP.push({i,j});
                    visP[i][j]=1;
                }
            }
        }

        while(!qA.empty()){
            auto [x,y] = qA.front(); qA.pop();
            for(auto [dx,dy]: dirs){
                int i = x+dx, j=y+dy;
                if(i>=0 && j>=0 && i<m && j<n && !visA[i][j] and heights[x][y]<=heights[i][j]){
                    qA.push({i,j});
                    visA[i][j]=1;
                }
            }
        }
        vector<vector<int>>res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visP[i][j] and visA[i][j]){
                    res.push_back({i,j});
                }
            }
        }
        return res;
    }
};
