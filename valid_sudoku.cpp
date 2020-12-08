# Given a board, determine if it has a valid sudoku. The board has valid sudoku if
  # Each row has 1-9 without repitition
  # Each column has 1-9 without repitition
  # Each of the 3*3 sub grids has 1-9 wihtout repitition
  
# Example Input - 
#                 [["5","3",".",".","7",".",".",".","."]
#                 ,["6",".",".","1","9","5",".",".","."]
#                 ,[".","9","8",".",".",".",".","6","."]
#                 ,["8",".",".",".","6",".",".",".","3"]
#                 ,["4",".",".","8",".","3",".",".","1"]
#                 ,["7",".",".",".","2",".",".",".","6"]
#                 ,[".","6",".",".",".",".","2","8","."]
#                 ,[".",".",".","4","1","9",".",".","5"]
#                 ,[".",".",".",".","8",".",".","7","9"]]

# Expected output - True.

#include <iostream>
#include <unordered_map>

bool isValidSudoku(vector<vector<char>>& board) 
{
        std::unordered_map<char,int> fmap;
        
        for(int i=0; i<board.size(); i++)
        {
            for(int j=0; j<board[0].size(); j++)
            {
                if(board[i][j] != '.') 
                {
                    if(!fmap[board[i][j]])
                        fmap[board[i][j]]++;
                    else
                        return false;
                }
            }
            fmap.clear();
        }
        
        for(int j=0; j<board.size(); j++)
        {
            for(int i=0; i<board[0].size(); i++)
            {
                if(board[i][j] != '.') 
                {
                    if(!fmap[board[i][j]])
                        fmap[board[i][j]]++;
                    else
                        return false;
                }
            }
            fmap.clear();
        }
        
        int i=0;
        while(i<board.size())
        {
            int j=0;
            while(j<board[0].size())
            {
                int m = i;
                while(m < i+3)
                {
                    int k = j;
                    while(k<j+3)
                    {
                        if(board[m][k] != '.') 
                        {
                            if(!fmap[board[m][k]])
                                fmap[board[m][k]]++;
                            else
                                return false;
                        }
                        k++;
                    }
                    m++;
                }
                fmap.clear();
                j += 3;
            }
            i += 3;
        }
        return true;  
}

int main()
{
        vector<vector<char>> board {{"5","3",".",".","7",".",".",".","."}
        ,{"6",".",".","1","9","5",".",".","."}
        ,[".","9","8",".",".",".",".","6","."}
        ,{"8",".",".",".","6",".",".",".","3"}
        ,{"4",".",".","8",".","3",".",".","1"}
        ,{"7",".",".",".","2",".",".",".","6"}
        ,{".","6",".",".",".",".","2","8","."}
        ,{".",".",".","4","1","9",".",".","5"}
        ,{".",".",".",".","8",".",".","7","9"}};

        std::cout << isValidSudoku(board) << std::endl;
        return 0;
}
