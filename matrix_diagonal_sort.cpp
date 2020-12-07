// Given an m*n matrix sort them in ascending order diagonally from top left to bottom right

// Example Input   - [[3,3,1,1],
//                    [2,2,1,2],
//                    [1,1,1,2]]

// Expected Output - [[1,1,1,1],
//                    [1,2,2,2],
//                    [1,2,3,3]]

#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    
    int r = (int)mat.size()-1;
    int c = (int)mat[0].size()-1;
    
    vector<vector<int>> ans(r+1, vector<int> (c+1,0));;
    vector<int> temp;
    
    int i = r;
    int j = 0;
    
    int check = r+c+1;
    
    while(check--)
    {
        if(i>=0)
        {
            temp.push_back(mat[i][j]);
            int count = 1;
            while((i+count)<=r && (j+count)<=c)
            {
                temp.push_back(mat[i+count][j+count]);
                count++;
            }
            sort(temp.begin(),temp.end());
            while(count--)
            {
                ans[i+count][j+count] = temp.back();
                temp.pop_back();
            }
            if(i>0)
                i--;
            else if(i==0)
                j++;
        }
    }
      return ans;
}

int main(int argc, const char * argv[]) {
      vector<vector<int>> x{{3,3,1,1},{2,2,1,2},{1,1,1,2}};
      vector<vector<int>> res = diagonalSort(x);
      
      for(auto x: res)
      {
            for(auto y: x)
            {
                  cout<<y<<" ";
            }
            cout<<endl;
      }
      return 0;
}
