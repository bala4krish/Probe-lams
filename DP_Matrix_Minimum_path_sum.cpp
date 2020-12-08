// A classical dynamic programming problem. Finding the path from top left to the bottom right of the matrix minimizing the sum along it's path.

        // Example Input     -     [[1,3,1],
        //                          [1,5,1],
        //                          [4,2,1]]

        // Expected Output   -      7. Path = 1->3->1->1->1
        
        
#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[i].size(); j++)
            {
                if(i==0 && j>0)
                    grid[i][j] += grid[i][j-1];
                else if(j==0 && i>0)
                    grid[i][j] += grid[i-1][j];
                else if(i&&j)
                    grid[i][j] += std::min(grid[i-1][j],grid[i][j-1]);
            }
        }
        return grid.back().back();
}

int main()
{
        std::vector<std::vector<int>> fvec {{1,3,1},{1,5,1},{4,2,1}};
        std::cout << minPathSum(fvec) << std::endl;
        return 0;
}
