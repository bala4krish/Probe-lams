// Rotting oranges using breadth first search.

// Given a grid, each cell has an integer representing,
          // 0 - Empty cell
          // 1 - fresh orange
          // 2 - rotten orange
// Every minute, a fresh orange that is adjacent 4 directionally to a rotten orange becomes rotten.
// Return the total number of minutes before all the oranges are rotten or -1 when that is not possible.


        // Example Input     -     [[2,1,1],
        //                          [1,1,0],
        //                          [0,1,1]]

        // Expected Output   -      4.


#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>>& grid) 
{
        if(grid.empty() || grid[0].empty())
            return 0;
        int H = grid.size();
        int W = grid[0].size();
        int minutes = 0;
        int temp = 0;
        vector<pair<int,int>> directions{{1,0},{0,1},{-1,0},{0,-1}};
        std::queue<pair<int,int>> fq;
        
        auto inside = [&](int i, int j){
            return 0 <= i && i < H && 0 <= j && j < W;
        };
        
        for(int row = 0; row < H; row++)
        {
            for(int col =0; col < W; col++)
            {
                if(grid[row][col] == 1)
                    temp++;
                else if(grid[row][col] == 2)
                    fq.push({row,col});
            }
        }
        
        while(!fq.empty())
        {
            int sz = fq.size();
            int prev_temp = temp;
            while(sz--)
            {
                pair<int,int> fpair = fq.front();
                fq.pop();
                for(pair<int,int> dir : directions)
                {
                    int new_row = fpair.first + dir.first;
                    int new_col = fpair.second + dir.second;
                    if(inside(new_row, new_col) && grid[new_row][new_col] == 1)
                    {
                        grid[new_row][new_col] = 2;
                        fq.push({new_row, new_col});
                        temp--;
                    }
                }
            }
            if(prev_temp > temp)
                minutes++;
        }

        if(temp)
            return -1;
        else
            return minutes;
        
}

int main()
{
        std::vector<std::vector<int>> fvec {{1,1,1},{1,1,0},{1,0,1}};
        std::cout << orangesRotting(fvec) << std::endl;
        return 0;
}
