# Given an array of integers (positive & negative), this code will find the maximum product of three numbers in O(n) time.
# Example Input - [-1,-11,3,4,5,6,10]
# Expected Output - 300.

#include <iostream>
#include <vector>

int maximumProduct(vector<int>& nums) 
{
        int max1, max2, max3, min1, min2;
        max1 = max2 = max3 = INT_MIN;
        min1 = min2 = INT_MAX;
        for(int& num : nums)
        {
            if(num > max1)
            {
                max3 = max2;
                max2 = max1;   
                max1 = num;
            }
            else if(num > max2)
            {
                max3 = max2;
                max2 = num;
            }
            else if(num > max3)
                max3 = num;
            
            if(num < min1)
            {
                min2 = min1;
                min1 = num;
            }
            else if(num < min2)
                min2 = num;
        }
        return std::max(max1*max2*max3, min1*min2*max1);     
}

int main()
{
  std::vector<int> vec_in {-1,-11,3,4,5,6,10};
  std::cout << "The max product is : " << maximumProduct(vec_in);
}
    
