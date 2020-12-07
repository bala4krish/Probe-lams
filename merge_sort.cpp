// Merge Sort

#include <iostream>
#include <vector>
using std::vector;

void Merge(vector<int>& left, vector<int>& right, vector<int>& array)
{
    int i = 0;
    int j = 0;
    int k = 0;
    int nleft = (int)left.size();
    int nright = (int)right.size();
      
    while(i<nleft && j<nright)
    {
        if(left[i]>right[j])
        {
            array[k]=right[j];
            j++;
        }
        else
        {
            array[k] = left[i];
            i++;
        }
        k++;
    }
    while(i<nleft)
    {
        array[k] = left[i];
        i++;
        k++;
    }
    while(j<nright)
    {
        array[k] = right[j];
        j++;
        k++;
    }
    left.clear();
    right.clear();
    left.shrink_to_fit();
    std::cout<<left.capacity()<<"\n";
}

void Sort(vector<int>& array)
{
    int n = (int)array.size();
    if(n<2)
        return;
    int mid = n/2;
    vector<int> left(array.begin(),array.begin()+mid);
    vector<int> right(array.begin()+mid,array.end());
    Sort(left);
    Sort(right);
    Merge(left,right,array);
}


int main() {     
      vector<int> input({5,1,1,2,0,0});
      Sort(input);
      for(int x : input)
            std::cout<<x<<" ";
      std::cout<<std::endl;
      return 0;
}
