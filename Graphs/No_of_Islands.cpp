class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        if(n==0)
            return 0;
        int m=grid[0].size();
        if(m==0)
            return 0;
        int island_count = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == '1')
                {
                    island_count += Islandutil(grid,i,j);
                }
            }
        }
        
        return island_count;
    }
    
    int Islandutil(vector<vector<char>>& grid, int i, int j) {
        if ( i<0 || i>=grid.size() || j<0 || j>=grid[i].size() || grid[i][j] == '0')
            return 0;
        
        grid[i][j] = '0';
        
        Islandutil(grid,i+1,j);
        Islandutil(grid,i-1,j);
        Islandutil(grid,i,j+1);
        Islandutil(grid,i,j-1);
        
        return 1;
    }
    
};