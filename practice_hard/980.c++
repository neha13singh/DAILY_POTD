class Solution {
public:int row, col;
vector<int>rowdir={0,1,0,-1};
vector<int>coldir={1,0,-1,0};
int totalcount;
    int solve(vector<vector<int>>& grid,vector<vector<int>>&visited, int count,int i,int j)
    {
        if(i>=row || j>=col || i<0 || j<0)return 0;
        if(visited[i][j]==1)
        {
            return 0;
        }
         else if(grid[i][j]==-1)
        {
            return 0;
        }
        

        
        if(grid[i][j]==2 && totalcount+2==count)
        {
            return 1;
        }
        else if(grid[i][j]==2 && totalcount+2!=count){
            return 0;
        }
        visited[i][j]=1;
       
     
      
                int left=solve(grid,visited,count+1, i+rowdir[0],j+coldir[0]);
  
               int  down=solve(grid,visited,count+1,  i+rowdir[1],j+coldir[1]);

               int  up=solve(grid,visited,count+1,  i+rowdir[2],j+coldir[2]);
       
              int  right=solve(grid,visited,count+1,  i+rowdir[3],j+coldir[3]);
                
            visited[i][j]=0;

            return left+right+down+up;
        
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
     row=grid.size();
     col=grid[0].size(); int count=0;  totalcount=0;
     vector<vector<int>>visited(row,vector<int>(col,0));
      for(int i=0; i<row; i++)
     {
        for(int j=0; j<col; j++)
        {
            if(grid[i][j]==0)
            {
                totalcount++;
                
            }
        }
     }
     for(int i=0; i<row; i++)
     {
        for(int j=0; j<col; j++)
        {
            if(grid[i][j]==1)
            {
                return solve(grid,visited,1,i,j);
            }
        }
     }
     return solve(grid,visited,0,0,0);
    }
}; 