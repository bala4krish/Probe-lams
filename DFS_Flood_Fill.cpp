// Flood fill using depth first search

// Given an image, the starting pixel and the new color, fill the image with the new color if
      // the 4 directional pixels are of same color as the starting pixel and,
      // their 4 directional pixels are of same color as the starting pixel and so on ...
      
// Example input - 
//                  [[1,1,1],
//                  [1,1,0],
//                  [1,0,1]]
//                  sr = 1, sc = 1, newColor = 2

// Expected output - 
//                  [[2,2,2],
//                   [2,2,0],
//                   [2,0,1]]


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) 
{
        int H = image.size();
        int W = image[0].size();
        int col = image[sr][sc];
        image[sr][sc] = newColor;
        std::queue<pair<int,int>> fq;
        fq.push({sr,sc});
        vector<pair<int,int>> directions {{1,0},{0,1},{-1,0},{0,-1}};
        vector<vector<bool>> vis(H, vector<bool>(W));
        
        auto inside = [&](int i, int j){
            return (0 <= i && i< H && 0 <= j && j < W); };
        
        while(!fq.empty())
        {
            pair<int,int> fpair = fq.front();
            fq.pop();
            vis[fpair.first][fpair.second] = true;
            for(pair<int,int> dir : directions)
            {
                int new_sr = fpair.first + dir.first;
                int new_sc = fpair.second + dir.second;
                if(inside(new_sr,new_sc) && !vis[new_sr][new_sc] && image[new_sr][new_sc] == col)
                {
                    image[new_sr][new_sc] = newColor;
                    fq.push({new_sr,new_sc});
                    vis[new_sr][new_sc] = true;
                }
            }
        }
        return image;
}

int main()
{
        std::vector<std::vector<int>> fvec {{1,1,1},{1,1,0},{1,0,1}};
        floodFill(fvec);
        for(auto& vec : fvec)
        {
            for(int& num : vec)
            {
                std::cout << num << ",";
            }
            std::cout << "\n" << std::endl;
        }
        return 0;
}
