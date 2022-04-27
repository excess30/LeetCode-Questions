class Solution {
public:
    
    void imgColor(vector<vector<int>>& image, int i, int j, int newColor, int oldColor)
    {
        if(i<0||i>=image.size()||j<0||j>=image[0].size()||image[i][j]==newColor||image[i][j]!=oldColor)
        {
            return;
        }
        image[i][j]=newColor;
        imgColor(image,i+1,j,newColor,oldColor);
        imgColor(image,i-1,j,newColor,oldColor);
        imgColor(image,i,j+1,newColor,oldColor);
        imgColor(image,i,j-1,newColor,oldColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
    {
        imgColor(image,sr,sc,newColor,image[sr][sc]);
        return image;
    }
};