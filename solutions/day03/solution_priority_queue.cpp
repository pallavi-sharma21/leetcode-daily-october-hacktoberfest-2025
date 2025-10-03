class Solution {
public:
    //alias 
    using P = pair<int, pair<int,int>>;

    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n= heightMap[0].size();
      
        //directions
        vector<pair<int,int>>dirs= {{0,1}, {0,-1}, {1,0}, {-1,0}};
      
        //visit map initialized with 0
        vector<vector<int>>vis(m, vector<int>(n,0));
      
        //min heap
        priority_queue<P, vector<P>, greater<P>>pq;

        for(int i=0;i<m;i++){ //row boundary
            vis[i][0]=1;
            vis[i][n-1]=1;
            pq.push({heightMap[i][0], {i,0}});
            pq.push({heightMap[i][n-1], {i,n-1}});
        }

        for(int j=0;j<n;j++){ //col boundary
            vis[0][j] =1;
            vis[m-1][j]=1;
            pq.push({heightMap[0][j],{0,j}});
            pq.push({heightMap[m-1][j],{m-1, j }});
        }
      
        int ans=0;
        while(!pq.empty()){
            int h= pq.top().first;
            int x= pq.top().second.first;
            int y= pq.top().second.second;
            pq.pop();
            for(auto [dx,dy] : dirs){
                int i= x+dx;
                int j= y+dy;
                if(i>=0 and i<m and j>=0 and j<n and !vis[i][j]){
                    ans+=max(0, h-heightMap[i][j]);
                    pq.push({max(h, heightMap[i][j]), {i,j}});
                    vis[i][j]=1;
                } 
            }
        }
        return ans;

    }
};
