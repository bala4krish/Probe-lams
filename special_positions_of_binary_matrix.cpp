// Count the special positions of a given binary matrix. 
// A position is special if the matrix cell has 1 and all the cells of the corresponding row as well as the column are zero.


        // Example Input     -     [[1,0,0],
        //                          [0,0,1],
        //                          [1,0,0]]

        // Expected Output   -      1. Only the cell(1,2) is special.


#incldue <iostream>
#include <vector>
#include <queue>
using namespace std;

int numSpecial(vector<vector<int>>& mat) {
        
        int count = 0;
        int H = mat.size();
        int W = mat[0].size();
        
        auto row_wise = [&](int row, int col){
            for(int r = 0; r < H; r++)
                if(r != row && mat[r][col])
                    return false;
            return true;
        };
        
        auto col_wise = [&](int row, int col){
            for(int c = 0; c < W; c++)
                if(c != col && mat[row][c])
                    return false;
            return true;
        };
        
        for(int row = 0; row < H; row++)
            for(int col = 0; col < W; col++)
                if(mat[row][col] && row_wise(row,col) && col_wise(row,col))
                    count++;   

        return count;
}

int main()
{
        std::vector<std::vector<int>> fvec {{1,0,0},{0,0,1},{1,0,0}};
        std::cout << numSpecial(fvec);
        return 0;
}
