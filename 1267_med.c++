class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int r=grid.size(); int c=grid[0].size();
        vector<int>rows(grid.size());
        vector<int>cols(grid[0].size());
        for(int i=0; i<r; i++)
        {
            int count=0;
            for(int j=0; j<c; j++)
            {
                if(grid[i][j]==1)
                {
                    count++;
                }

            }
            rows[i]=count;      
              }
//for accessing count of servers in each row
            for(int i=0; i<c; i++)
        {
            int count=0;
            for(int j=0; j<r; j++)
            {
                if(grid[j][i]==1)
                {
                    count++;
                }

            }
            cols[i]=count;      
              }
// for accessing number of servers in each column
              int ans=0;
          
            for(int i=0; i<r; i++)
            {
                for(int j=0; j<c; j++)
                {
                    if(grid[i][j]==1)
                    {
                        if(cols[j]>1 || rows[i]>1)
                        {
                            ans++;
                        }
                    }
                }
            }
            // int ans=0;
            // for(int i=0; i<grid.size(); i++)
            // {
            //     for(int j=0; j<grid[0].size(); j++)
            //     {
            //         if(result[i][j]==1)
            //         {
            //            ans++;
            //         }
            //     }
            // }
            return ans;

    }
};