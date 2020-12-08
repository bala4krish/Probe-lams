# This code generates the beautiful pascal's triangle for a given number of rows.
    # Example input - 5
    # Expected output
    #                       [
    #                             [1],
    #                            [1,1],
    #                           [1,2,1],
    #                          [1,3,3,1],
    #                         [1,4,6,4,1]
    #                       ]


#include <iostream>
#include <vector>

std::vector<std::vector<int>> fvec{{1}};

vector<vector<int>> generate(int numRows) {
        if(!numRows)
            return {};
        
        for(int i=1; i<numRows; i++)
        {
            std::vector<int> temp(i+1,1);
            temp.front() = fvec[i-1].front();
            temp.back() = fvec[i-1].back();
            
            for(int j=1; j<i; j++)
                temp[j] = fvec[i-1][j-1] + fvec[i-1][j];
            
            fvec.push_back(temp);
        }
        return fvec;
}

int main()
{
        generate(5);
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
