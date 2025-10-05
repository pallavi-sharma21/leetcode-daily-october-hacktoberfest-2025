#include<bits/stdc++.h>
using namespace std; 

class DSU {
public:
    vector<int> parent;
    DSU(int n) { parent.resize(n); iota(parent.begin(), parent.end(), 0); }
    int find(int x) { return parent[x]==x ? x : parent[x]=find(parent[x]); }
    void unite(int x, int y) { parent[find(x)] = find(y); }
};

class Solution {
public:
    vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size(), n=heights[0].size();
        int pacNode = m*n, atlNode = m*n+1;
        DSU dsu(m*n+2);
        
        auto idx=[&](int i,int j){ return i*n+j; };
        
        for(int i=0;i<m;i++){
            dsu.unite(idx(i,0), pacNode);
            dsu.unite(idx(i,n-1), atlNode);
        }
        for(int j=0;j<n;j++){
            dsu.unite(idx(0,j), pacNode);
            dsu.unite(idx(m-1,j), atlNode);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(auto &d:dirs){
                    int x=i+d[0], y=j+d[1];
                    if(x>=0 && y>=0 && x<m && y<n && heights[x][y] <= heights[i][j]){
                        dsu.unite(idx(i,j), idx(x,y));
                    }
                }
            }
        }
        
        vector<vector<int>> res;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dsu.find(idx(i,j))==dsu.find(pacNode) && dsu.find(idx(i,j))==dsu.find(atlNode))
                    res.push_back({i,j});
            }
        }
        return res;
    }
};
