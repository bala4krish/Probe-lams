// This code finds the indices of two elements that sum up to the target.

#include <iostream>
#include <vector>
#include <unordered_set>
using std::cout;
using std::endl;
using std::vector;

bool TwoSum(const vector<int>& nums, int target, std::pair<int,int>& anspair)
{
      bool pair = false;
      std::unordered_set<int> fmap;
      for(int i=0; i<nums.size(); i++)
      {
            if(fmap.find(nums[i])!=fmap.end())
            {
                  pair = true;
                  anspair.first = target - nums[i];
                  anspair.second = nums[i];
                  break;
            }
            else
                  fmap.insert(target-nums[i]);
      }
      return pair;
}

void printNums(const vector<int>&& nums, int target)
{
      std::pair<int,int> anspair;
      bool result = TwoSum(nums, target, anspair);
      if(result)
            cout<<"the pair is : "<<anspair.first<<"\t"<<anspair.second<<endl;
      else
            cout<<"no pair found"<<endl;
}
               
int main()
{
      vector<int> input = {1,5,7,8,9,15};
      printNums({1,5,7,8,9,15},8);
      return 0;
}
