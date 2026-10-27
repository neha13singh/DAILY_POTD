class Solution {
public:
   int m,n;
   
    void dfs(vector<vector<int>>& image, int i, int j, int color,int color2)
    {
        if(i>=m || i<0 || j>=n || j<0)
        {
            return;
        }
       if(image[i][j]==color)
       {
        return;
       }
       if(image[i][j]!=color2)
       {
        return;
       }
        image[i][j]=color;
        dfs(image,i+1,j,color,color2);
        dfs(image,i-1,j,color,color2);
        dfs(image,i,j+1,color,color2);
        dfs(image,i,j-1,color,color2);

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        m=image.size();
        n=image[0].size();
        // image[sr][sc]=1;
        dfs(image,sr,sc,color, image[sr][sc]);
        return image;
        
    }
};